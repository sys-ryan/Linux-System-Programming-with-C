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
                sleep(500);
                exit(3);
        }
}

/*
root@ryan:~/linux-system-programming-with-C# kill 68141


root@ryan:~/linux-system-programming-with-C# ./exit-status-demo
parent waiting for child ...
child running -- PID is 68141
child terminated by signal 15
*/

/*
root@ryan:~/linux-system-programming-with-C# kill -9 68167


root@ryan:~/linux-system-programming-with-C# ./exit-status-demo
parent waiting for child ...
child running -- PID is 68167
child terminated by signal 9
*/
