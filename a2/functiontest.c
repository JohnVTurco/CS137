#include <stdio.h>

int isPrime(int num){
    int div = 2;
    if(num <= 1){ return 0;}
    else{
        while(div*div < num){
            if(num % div == 0){
                return 0; 
            }
            div++;
        }
    }
    return 1;
}

int isSophieGermainPrime(int n){
    if(isPrime(n)){
        if(isPrime(2*n + 1)){
            return 1;
        }   
    }
        return 0;
}

int base2nat(int bs, int num){
    int decimal = 0, power = 1;
    while(num > 0){
        decimal += (num % 10) * power;
        power = power * bs;
        num /= 10;
    }
    return decimal;
}

int nat2base(int bs, int num){
    int multiplier = 1, baseNum = 0;
    while(num > 0){
        if(num % bs != 0){
            baseNum += (num % bs) * multiplier;
            num -= (num % bs);
        }
        num = num / bs;
        multiplier *= 10;
    }
    return baseNum;
}


int main(void){
   printf("%d", nat2base(4, 3055));
}