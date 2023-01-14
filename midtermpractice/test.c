#include <stdio.h>

void sizeArray (int a[]){
    printf("%d", sizeof(a));
}

int main (void){
    int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", sizeof(a));
    //sizeArray(a);
}