#include <sys/stat.h>

void main(){
        umask(0);
        creat("f1", 0755);

        umask(007);
        creat("f2", 0755);

        creat("f3", 0);
        chmod("f3", S_IRUSR | S_IWUSR);

        system("ls -l f?");
}

/*
root@ryan01:/home/ryan01/linux_system_programming/06# ./makesomefiles
-rwxr-xr-x 1 root root 0  8월 31 11:03 f1
-rwxr-x--- 1 root root 0  8월 31 11:03 f2
-rw------- 1 root root 0  8월 31 11:03 f3
*/
