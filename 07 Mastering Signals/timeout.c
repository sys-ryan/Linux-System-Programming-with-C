#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <stdlib.h>

void timeout_handler(int unused){
        /* Nothing to do */
}


int t_getnum(int timeout){
        int n;
        char line[100];
        struct sigaction action;

        action.sa_handler = timeout_handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = 0; /* important! */
        sigaction(SIGALRM, &action, NULL);

        alarm(timeout);
        n = read(0, line, 100);
        alarm(0); /* Cancel alarm */
        if(n == -1 && errno == EINTR) return -1;
        n = atoi(line);
        return n;
}

void main(){
        int num;

        while(1){
                printf("enter a number: "); fflush(stdout);
                if((num = t_getnum(5)) == -1){
                        printf("timed out!\n");
                }
                else{
                        printf("You entered %d\n", num);
                }

        }
}

/*
ryan01@ryan01:~/linux_system_programming/07$ ./timeout
enter a number: 1
You entered 1
enter a number: 74
You entered 74
enter a number: 22
You entered 22
enter a number: 13324
You entered 13324
enter a number: timed out!
enter a number: timed out!
enter a number: ^C
ryan01@ryan01:~/linux_system_programming/07$

*/
