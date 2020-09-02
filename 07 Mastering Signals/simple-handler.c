#include <stdio.h>
#include <signal.h>
#include <sys/wait.h>
#include <stdlib.h>

int n;

void handler(int signum){
        printf("signal %d received - counter reset\n", signum);
        n = 0;
}

main(){
        signal(SIGINT, handler);
        signal(SIGQUIT, SIG_IGN);
        signal(SIGTERM, SIG_IGN);
        while(1){
                printf("Working %d\n", n++);
                sleep(1);
        }
}


/*
ryan01@ryan01:~/linux_system_programming/07$ ./simple-handler
Working 0
Working 1
Working 2
Working 3
^Csignal 2 received - counter reset
Working 0
Working 1
Working 2
Working 3
Working 4
Working 5
^Csignal 2 received - counter reset
Working 0
Working 1
Working 2
*/
