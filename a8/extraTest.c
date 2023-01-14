#include <stdio.h>
#include <string.h>

int main (void){
    int arr[13] = {1,4,5,7,12,23,44,67,89,100,120,121,122};
    int x=121;
    int BB = 0; int BA = 13 - 1;
    int Pos;
    
    Pos = (BB + ((float)(x - arr[BB])/(arr[BA] - arr[BB]))*(BA-BB));
    printf("%d", Pos);

   
}