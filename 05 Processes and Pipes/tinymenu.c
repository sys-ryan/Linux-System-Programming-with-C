/* File tinymenu.c */

#include <stdio.h>
#include <unistd.h>

void main(){
        static char *cmd[] = { "ps", "ls", "date", "goof" };
        int i;

        printf("0=ps, 1=ls, 2=date, 3=good : ");
        scanf("%d", &i);

        execlp(cmd[i], cmd[i], NULL);

        printf("command not found\n");
}




/*
root@ryan:~/linux-system-programming-with-C# ./tinymenu
0=ps, 1=ls, 2=date, 3=good : 2
2020. 08. 18. (화) 21:46:04 KST
root@ryan:~/linux-system-programming-with-C# ./tinymenu
0=ps, 1=ls, 2=date, 3=good : 0
    PID TTY          TIME CMD
   3077 pts/0    00:00:00 su
   3079 pts/0    00:00:00 bash
  60971 pts/0    00:00:00 ps
root@ryan:~/linux-system-programming-with-C# ./tinymenu
0=ps, 1=ls, 2=date, 3=good : 3
command not found
*/
