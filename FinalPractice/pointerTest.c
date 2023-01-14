#include <stdio.h>

int main (void){
    int x = 4;
    int y = 10;
    int *px = &x;
    int *py = &y;
  
    px = py;
    *px =8;
    printf("%d", y);
}