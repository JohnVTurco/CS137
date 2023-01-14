#include <stdio.h>
#include <stdlib.h>

int main (void){
    int *t = malloc(5 * sizeof(int));

    for(int i = 0; i < 5; i++){
        t[i] = i;
    }
    t+= 1;
    printf("%d", *t);
}