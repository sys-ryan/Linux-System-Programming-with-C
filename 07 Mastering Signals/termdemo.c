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
                sleep(3);
                exit(5);
        }
}
