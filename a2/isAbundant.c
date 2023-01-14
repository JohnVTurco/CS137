#include <stdio.h>

int main (void){
    int input, sum = 1;
    scanf("%d", &input);

    for(int i = 2; i <= input/2; i++){
        if(input % i == 0){
            sum += i;
        }
    }

    if(sum == input){
        printf("Perfect\n");
    }
    else if(sum > input){
        printf("Abundant\n");
    }
    else{
        printf("Deficient\n");
    }

    return 0;
}