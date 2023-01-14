#include <stdio.h>
int main(void){
    int num, denom, answer;
    scanf("%d %d", &num, &denom);
    printf("%d\n", num % denom == 0 ? num/denom : num * denom >= 0 ? num/denom + 1 : num/denom - 1);
    return 0;
} 