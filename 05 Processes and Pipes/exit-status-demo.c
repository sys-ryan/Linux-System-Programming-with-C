/* Exit status Demo */

#include <stdio.h>
#include <stdlib.h>

int main(){
        int status;
        if(fork()){
                /* Parent */
                printf("parent waiting for child ...\n");
                wait(&status);
                if(WIFEXITED(status)){
                        printf("child ended normally, exit status = %d\n", WEXITSTATUS(status));
                }
                if(WIFSIGNALED(status)){
                        printf("child terminated by signal %d\n", WTERMSIG(status));
                }
        }
        else {
                /* Child */
                printf("child running -- PID is %d\n", getpid());
                sleep(5);
                exit(3);
        }
}


/*

root@ryan:~/linux-system-programming-with-C# ./exit-status-demo
parent waiting for child ...
child running -- PID is 67661
child ended normally, exit status = 3

*/
