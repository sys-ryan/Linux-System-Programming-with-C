#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int count; /* Global state information */
void print_state_info(int sig){
        printf("%d blocks copies\n", count);
}

void main(){
        signal(SIGUSR1, print_state_info);
        for(count = 0; count < A_BIG_NUMBER; count++){
                read_block_from_inpuit_teapte();
                write_block_to_output_tapte();
        }
}
