#include <stdio.h>
#include <stdlib.h>

int readSum(){
    int sum = 0;
    int num;
    char letter;

    while(1){
        if(scanf("%d ", &num)){
            sum+=num;
        }
        else if(scanf("%c ", &letter)){
            if(letter >= 'A' || letter <= 'F'){
                sum+= letter - 'A' + 10;
            }
        }
        else{
            break;
        }
    }

}

int main (void){
    printf("%d\n", readSum());
    return 0;
}