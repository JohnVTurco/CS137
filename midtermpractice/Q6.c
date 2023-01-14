#include <stdio.h>
#include <stdbool.h>

int main(void){
    int digits[9] = {0};
    bool notExist = false;
    int input, temp;

    scanf("%d", &input);
    
    while(input > 0){
        temp = input;

        while(temp > 0){
            if(digits[temp%10 -1] == 0){
                notExist = true;
            }
            digits[temp%10 -1]++;
            temp /= 10;
        }
        if(notExist){
            printf("%d\n", input);
        }
        scanf("%d", &input);
        notExist = false;   
    }
    return 0;
}