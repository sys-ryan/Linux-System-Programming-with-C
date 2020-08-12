/* A simple version of ls */

#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <time.h>
#include <dirent.h>
#include <string.h>

void listfile(char *name){
  struct stat sb ;      /* The stat buffer */
  char *modtime;

  /* Array of file types, indexed by the top four bits of st_mode */

  char *filetype[] = { "?", "p", "c", "?", "d", "?", "b", "?", "-", "?", ";", "?", "s" };

  if(stat(name, &sb) < 0){
    perror(name);
    exit(2);
  }

  /* File type (using same indicator characters as ls) */
  printf("%s", filetype[(sb.st_mode >> 12) & 017]);

  /* Permissions (same as ls) */
  printf("%c%c%c%c%c%c%c%c%c",
            (sb.st_mode & S_IRUSR) ? 'r' : '-',
            (sb.st_mode & S_IWUSR) ? 'w' : '-',
            (sb.st_mode & S_IXUSR) ? 'x' : '-',
            (sb.st_mode & S_IRGRP) ? 'r' : '-',
            (sb.st_mode & S_IWGRP) ? 'w' : '-',
            (sb.st_mode & S_IXGRP) ? 'x' : '-',
            (sb.st_mode & S_IROTH) ? 'r' : '-',
            (sb.st_mode & S_IWOTH) ? 'w' : '-',
            (sb.st_mode & S_IXOTH) ? 'x' : '-' );

  printf("%8ld", sb.st_size);

  modtime = ctime(&sb.st_mtime);
  /* ctime() string has \n at end, we need to remove this */
  modtime[strlen(modtime) - 1] = '\0';
  printf("  %s  ", modtime);
  printf("%s\n", name);
}


int main(int argc, char * argv[]){
  DIR *d;
  struct dirent *info;

  if(argc != 2){
    fprintf(stderr, "usage: listdir dirname\n");
    exit(1);
  }
  chdir(argv[1]);
  d = opendir(".");

  while((info = readdir(d)) != NULL){
    listfile(info->d_name);
  }
}



/*
ryan01@ryan01:~/linux_system_programming/03$ ./listdir .
-rw-r--r--      12  Tue Aug 11 14:36:07 2020  bar
-rw-r--r--    1448  Tue Aug 11 18:54:50 2020  listdir.c
-rwxr-xr-x   13024  Tue Aug 11 18:55:05 2020  listdir
-rwxr-xr-x    8592  Tue Aug 11 18:39:27 2020  dirtotal
-rw-r--r--    1108  Tue Aug 11 15:21:03 2020  listfile.c
-rw-r--r--     319  Tue Aug 11 14:31:39 2020  showtimes.c
-rw-r--r--     416  Tue Aug 11 18:39:15 2020  dirtotal.c
-rw-------      16  Tue Aug 11 14:36:52 2020  foo
drwxr-xr-x    4096  Tue Aug 11 19:15:28 2020  .
-rwxr-xr-x   12768  Tue Aug 11 15:22:06 2020  listfile
drwxr-xr-x    4096  Tue Aug 11 14:29:02 2020  ..
-rwxr-xr-x    8504  Tue Aug 11 14:31:59 2020  showtime

ryan01@ryan01:~/linux_system_programming/03$ ./listdir /
drwxrwxr-x    4096  Mon Aug 10 15:35:21 2020  cdrom
drwxr-xr-x    4096  Tue Aug 11 16:47:39 2020  snap
drwxr-xr-x    4096  Mon Aug 10 16:10:42 2020  lib64
drwxr-xr-x   12288  Tue Aug 11 11:18:40 2020  etc
-rw-r--r-- 9146616  Tue Feb  4 03:37:10 2020  vmlinuz.old
drwxr-xr-x    4096  Tue Feb  4 03:30:28 2020  var
drwxr-xr-x    4260  Tue Aug 11 16:47:39 2020  dev
-rw-------2147483648  Mon Aug 10 15:32:08 2020  swapfile
-rw-r--r--40785553  Mon Aug 10 17:00:39 2020  initrd.img
drwxr-xr-x    4096  Mon Aug 10 16:55:16 2020  bin
-rw-r--r--41437040  Mon Aug 10 16:57:07 2020  initrd.img.old
drwxr-xr-x    4096  Mon Aug 10 17:00:40 2020  boot
drwxr-xr-x    4096  Tue Feb  4 03:22:21 2020  srv
drwxr-xr-x    4096  Mon Aug 10 15:42:57 2020  lib
drwx------   16384  Mon Aug 10 15:31:42 2020  lost+found
dr-xr-xr-x       0  Mon Aug 10 15:57:23 2020  sys
drwxr-xr-x    4096  Tue Feb  4 03:25:36 2020  usr
drwxr-xr-x   12288  Mon Aug 10 16:55:16 2020  sbin
drwxr-xr-x    4096  Mon Aug 10 15:38:30 2020  home
drwxr-xr-x    4096  Mon Aug 10 15:55:31 2020  media
drwxr-xr-x    4096  Mon Aug 10 17:00:29 2020  .
drwx------    4096  Mon Aug 10 16:33:36 2020  root
drwxr-xr-x    4096  Tue Feb  4 03:22:21 2020  mnt
drwxr-xr-x    4096  Mon Aug 10 15:55:36 2020  opt
drwxr-xr-x     940  Tue Aug 11 11:18:44 2020  run
drwxrwxrwx    4096  Tue Aug 11 18:55:05 2020  tmp
drwxr-xr-x    4096  Mon Aug 10 17:00:29 2020  ..
-rw------- 9371904  Fri Jul 10 15:56:10 2020  vmlinuz
dr-xr-xr-x       0  Mon Aug 10 16:24:46 2020  proc

*/
