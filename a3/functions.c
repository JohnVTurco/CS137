#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

bool divide (int a, int b){
    if(b == 0){
        return true;
    }
    if(b < 0){
        b = 0 - b;
    }
    if(a < 0){
        a = 0 - a;
    }
    if(b < a){
        return false;
    }
    return divide(a, b - a);

}

int IntegerDivision(int a, int b){
    if(a < b){
        return 0;
    }
    return IntegerDivision(a - b, b) + 1;
    
}

int main(void){
    if(divide(7, 22)){
        printf("True\n");
    }
    printf("%d", IntegerDivision(151, 5));
}