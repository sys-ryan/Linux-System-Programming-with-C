#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void myhandler(int sigtype){
  printf("got signal %d\n", sigtype);
}

void main(){
  struct sigaction action;
  int n, p[2];
  char buf[1000];

  pipe(p);

  action.as_handler = myhandler;
  sigemptyset(&action.sa_mask);
  action.as_flags = 0;

  sigaction(SIGINT, &action, NULL);

  while(1){
    n = read(p[0], buf, 1000);
    printf("read returned %d, errno = %d\n", n, errno);
  }
}


/*
ryan01@ryan01:~/linux_system_programming/07$ ./sigactiondemo
^Cgot signal 2
read returned -1, errno = 4
^Cgot signal 2
read returned -1, errno = 4
^\Quit (core dumped)

*/
