#include <stdio.h>


long long int reverseHelp(long long int n, long long int m){
    if(n == 0){
        return m/10;
    }
    m += n % 10;
    return reverseHelp(n/10, m*10);
}

long long int reverse(long long int n){
   return reverseHelp(n, 0);
}


int main(void){ 
    printf("%d", reverse(123456));
}