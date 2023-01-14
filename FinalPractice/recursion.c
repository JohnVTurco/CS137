#include <stdio.h>


int countNum(long int n){
    int counter = 0;
    while(n > 0){
        counter++;
        n /= 10;
    }
    return counter;
}

int power(int n, int power){
    if(power == 1){
        return 1;
    }
    else{
        while(power > 1){
            n *= 10;
            power--;
        }
        return n;
    }
}

long int reverseNum(long int n) {
  if(n == 0){
    return 0;
  }
  else{
    int numCount = countNum(n);
    return (n%10) * power(1, numCount) + reverseNum(n/10);
  }
}



int main (void){
    long int n = reverseNum(123456789);
    printf("%d", n);
}