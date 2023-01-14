#include <stdio.h>

int sumDig(long long int n){
    int sum;
    do{
        sum = 0;
        while(n > 0){
            sum += n%10;
            n /= 10;
            
        }
        n = sum;
        
    }while(sum > 10);
    return sum;
}

int main (void){
   printf("%d", sumDig(12399987654020));
}