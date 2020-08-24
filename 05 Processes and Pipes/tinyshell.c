#include <unistd.h>
#include <stdlib.h>

/* A minimal shell */
int main(){
        char line[100];

        /* Main command loop */
        while(printf("> "), gets(line) != NULL){
                if(fork() == 0) {
                        /* Child */
                        execlp(line, line, (char *)0);

                        /*Don't come here unless execlp fails */
                        printf("%s: not found \n", line);
                        exit(1);
                }
                else wait(0); /* Parent */

                /* Now loop back and prompt again */
        }
}


/*

root@ryan:~/linux-system-programming-with-C# ./tinyshell
> date
2020. 08. 24. (월) 22:54:33 KST
> ls
exit-status-demo    forktest	timer	    tinyshell
exit-status-demo.c  forktest.c	timer.c     tinyshell.c
fork_loop	    strftime	tinymenu
fork_loop.c	    strftime.c	tinymenu.c
> ps
    PID TTY          TIME CMD
   3077 pts/0    00:00:00 su
   3079 pts/0    00:00:00 bash
  68235 pts/0    00:00:00 tinyshell
  68238 pts/0    00:00:00 ps
> ls -l
ls -l: not found
> root@ryan:~/linux-system-programming-with-C#

*/
