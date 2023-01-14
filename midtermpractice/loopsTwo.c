#include <stdio.h>

long int reverse (long int n){
    long int newNum = 0;
    while(n > 0){
        newNum *= 10;
        newNum += n % 10;
        n /= 10;
    }
    return newNum;
}



int main (void){
    for(int i = 0; i < 5;){
        printf("Hi");
    }
}