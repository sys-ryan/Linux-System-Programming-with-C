/* Simple demonstration of using signals to schedule periodic actions */

#include <stdio.h>
#include <signal.h>
#include <fcntl.h>

char *p, buffer[10000];

void handler(){
        int fd;

        fd = open("buffer.save", O_RDWR|O_CREAT|O_TRUNC, 0644);
        write(fd, buffer, p-buffer);
        close(fd);
        alarm(10);
}

void main(){
        int count;
        struct sigaction action;
        p = buffer;

        /* Establish SIGALRM handler */
        action.sa_handler = handler;
        sigemptyset(&action.sa_mask);
        action.sa_flags = SA_RESTART;
        sigaction(SIGALRM, &action, NULL);
        alarm(10);

        /* Accumulate text from stdin into buffer */
        while(count = read(0, p, 200))
                p += count;
}


/*
ryan01@ryan01:~/linux_system_programming/07$ ./periodic
hello world
linux programing with C
A is for apple
B is for Banana
c is for system programming
^C
*/




/*
ryan01@ryan01:~/linux_system_programming/07$ tail -f buffer.save
hello world
linux programing with C
A is for apple
B is for Banana
c is for system programming
^C
*/
