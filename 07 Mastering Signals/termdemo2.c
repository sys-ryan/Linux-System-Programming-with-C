#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
//#include sys<types.h>


int main(){
        int status;
        int a, b, c;

        if(fork()){
                /* Parent */
                wait(&status);
                if(WIFEXITED(status))
                        printf("Child exited normally with exit status %d\n", WEXITSTATUS(status));
                if(WIFSIGNALED(status))
                        printf("Child exited on signal %d: %s\n", WTERMSIG(status), strsignal(WTERMSIG(status)));
        }
        else {
                /* Child */
                printf("Child PID = %d\n", getpid());
                *(int *)0 = 99;
                sleep(3);
                exit(5);
        }
}


/*
ryan01@ryan01:~/linux_system_programming/07$ ./termdemo2
Child PID = 2736
Child exited on signal 11: Segmentation fault
ryan01@ryan01:~/linux_system_programming/07$

*/
