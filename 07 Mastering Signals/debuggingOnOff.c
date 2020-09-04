#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int debug_on = 0;

void toggle_debug_flag(int sig){
        debug_on ^= 1;
}

main(){
        signal(SIGHUP, toggle_debug_flag);

        /* Then sometime later in the code ... */

        if(debug_on){
                printf("something useful for debugging");
        }
}
