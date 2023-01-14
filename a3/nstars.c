#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

void stars(long int n){
    if(n < 10){
        printf("%d", n);
        return;
    }
    stars(n/10); 
    if(n % 10 == n/10 % 10){
        printf("*%d",n%10);
    }
    else{
        printf("%d", n%10);
    }
    
}

int main (void){
    stars(000000);
}