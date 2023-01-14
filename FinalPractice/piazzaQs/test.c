#include <stdio.h>
#include <stdlib.h>

int main(void){
    int *p = malloc(3*sizeof(int));
    p[0] = 1; 
    p[1] = 2;
    p[2] = 3;
    p = p +1;
    printf("%d", *p);
}