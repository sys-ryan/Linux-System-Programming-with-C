#include <stdio.h>

void main(){
        int i;
        if(fork()){
                for(i=0; i<100000; i++){
                        printf("**      parent %d\n", i);
                }
        }else {
                        for(i=0; i<100000; i++){
                                printf("        **      child %d\n", i);
                        }
        }
}

/*
 * The key point is that the parent and child output will be interleaved in
 * a non-deterministic way.
 */
