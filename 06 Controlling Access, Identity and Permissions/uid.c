/* Program to demonstrate real and effective IDs */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(){
        printf("Read            UID = %d\n", getuid());
        printf("Effective       UID = %d\n", geteuid());

        /* See if we can open hosts file for writing */
        printf("open: %d\n", open("/etc/hosts", O_RDWR));

        /* access() tests what the real user can do */
        printf("access: %d\n", access("/etc/hosts", W_OK));

        /* Now drop our root privilege and try again */
        seteuid(getuid());

        printf("Real            UID = %d\n", getuid());
        printf("Effective       UID = %d\n", geteuid());

        /* See if we can open hosts file for writing */
        printf("open: %d\n", open("/etc/hosts", O_RDWR));

        /* access() tests what the real user can do */
        printf("access: %d\n", access("/etc/hosts", W_OK));
}


/*
ryan01@ryan01:~/linux_system_programming/06$ ./uid
Read		UID = 1000
Effective	UID = 1000
open: -1
access: -1
Real		UID = 1000
Effective	UID = 1000
open: -1
access: -1


---

ryan01@ryan01:~/linux_system_programming/06$ sudo chown root ./uid
ryan01@ryan01:~/linux_system_programming/06$ sudo chmod u+s ./uid
ryan01@ryan01:~/linux_system_programming/06$ ls -l ./uid
-rwsr-xr-x 1 root root 8520  8월 27 13:32 ./uid

ryan01@ryan01:~/linux_system_programming/06$ ./uid
Read		UID = 1000
Effective	UID = 0
open: 3
access: -1
Real		UID = 1000
Effective	UID = 1000
open: -1
access: -1


*/
