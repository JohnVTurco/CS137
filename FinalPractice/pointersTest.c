#include <stdio.h> 

int main (void){
    int **p;
    int q = 10;
    int *r = &q;
    int x = 6;

    *p = r;
    *p = &x;
    **p = 11;
    *r = 8;

    printf("%d and %d", x, q);
}