#include <stdio.h>

int function1 (int n){
    for(int i = 1; i <= n; i++){
        for(int k = 1; k <=i; k++){
            printf("%d", k);
        }
        printf("\n");
    }
}

int function2 (int n){
    for(int i = 0; i < n; i++){
        for(int k = n - i; k > 0; k--){
            printf("%d", k);
        }
        printf("\n");
    }
}

int function3 (int n){
    for(int i = 0; i < n; i ++){
        for(int k = 1; k <= n - i; k++){
            printf("%d", k);
        }
        for(int l = n - i - 1; l  > 0; l--){
            printf("%d", l);
        }
        printf("\n");
    }
      
}

int main (void){
    function1(3);
    printf("\n\n");
    function2(3);
    printf("\n\n");
    function3(3);
}