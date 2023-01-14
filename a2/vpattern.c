#include <stdio.h>

int main(void){
    int input;
    scanf("%d", &input);

    for(int i = 1; i <= input; i++){

        for(int j = 1; j <= i; j++){
        printf("%d", j);
        }
        for(int k = input*2 - 2*i - 1; k >= 0; k--){
            printf(" ");
        } 
        for(int t = i; t >= 1; t--){
            printf("%d", t);
        }
        printf("\n");

    }
}
  
