#include <stdio.h>


int factorial(int n, int accum){
    if(n == 0 || n == 1){
        return accum;
    }
    else{
        return factorial(n-1, accum * n);
    }

}

int fact(int n){
    return factorial (5, 1);
}


int main(void){
    int factorial = fact(5);
}