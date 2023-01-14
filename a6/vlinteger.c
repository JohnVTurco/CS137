#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "vlinteger.h"
#include <stdbool.h>

struct linteger *vlintegerCreate(void){
    struct linteger *t1 = malloc(sizeof(struct linteger));
    t1->arr = NULL;
    t1->length = 0;
    return t1;

}

void vlintegerDestroy(struct linteger *v){
    if(v){
        free(v->arr);
        free(v);
    }
}

void vlintegerRead(struct linteger *t1){
    int num, counter = 0;
    t1->arr = malloc(0);
    while(scanf("%d", &num)){
        counter++;
        t1->arr = (int *) realloc(t1->arr, counter * sizeof(int));
        t1->arr[counter-1] = num;
    }
    t1->length = counter;
}


void vlintegerPrint(struct linteger *t1){
    printf("length=%d\n", t1->length);
    for(int i =0; i < t1->length; i++){
        printf("%d", t1->arr[i]);
    }
    printf("\n");
}

struct linteger * vlintegerAdd(struct linteger *t1, struct linteger *t2){
    struct linteger *tLarge;
    struct linteger *tSmall;
    int temp = 0;

    if(t1->length > t2->length){
        tLarge = t1;
        tSmall = t2;
    }
    else{
        tLarge = t2;
        tSmall = t1;
    }
    int *arrayThree = malloc(tLarge->length * sizeof(int));

    int tSmallval;
    int sum;
    for(int i = 0; i < tLarge->length; i++){
        if(tSmall->length - 1 - i >= 0){
            tSmallval = tSmall->arr[tSmall->length - 1 - i];
        } else {
            tSmallval = 0;
        }
        sum = tSmallval + tLarge->arr[tLarge->length-i-1] + temp;
        if(sum > 9){
            temp = 1;
            sum -= 10;
        }
        else{
            temp = 0;
        }

        arrayThree[i] = sum;
    }

    int finalLength = tLarge->length;
    if(temp == 1){
        arrayThree = (int *) realloc(arrayThree, tLarge->length * sizeof(int) + sizeof(int));
        arrayThree[tLarge->length] = 1;
        finalLength++;
    }

    int temporary;
    for(int k = 0; k < finalLength/2; k++){
        temp = arrayThree[k]; 
        arrayThree[k] = arrayThree[finalLength -1 - k];
        arrayThree[finalLength-1-k] = temp;
    }

    struct linteger *ans = vlintegerCreate();
    ans->arr = arrayThree;
    ans->length = finalLength;
   
    return ans;
}

struct linteger * vlintegerMult(struct linteger *t1, struct linteger *t2){
    struct linteger *final = vlintegerCreate();
    int zero=0;
    for(int i = t1->length-1; i >= 0; i--){
        int cur=t1->arr[i];
        struct linteger *current = vlintegerCreate();
        current->length=t2->length+1;
        current->arr=calloc(t2->length+1, sizeof(int));
        for(int j=t2->length-1;j>=0;j--){
            int sum=cur*t2->arr[j];
            current->arr[j+1]=current->arr[j+1]+sum%10;
            current->arr[j]=sum/10;
        }
        for(int p=0;p<zero;p++){
            current->length+=1;
            current->arr=realloc(current->arr,current->length*sizeof(int));
            current->arr[current->length-1]=0;
        }
        struct linteger *a = final;
        final=vlintegerAdd(current,final);
        vlintegerDestroy(a);
        vlintegerDestroy(current);
        zero++;
    }
    if(final->length!=0 && final->arr[0]==0){
        for(int i=0;i<final->length-1;i++){
            final->arr[i]=final->arr[i+1];
        }
        final->arr=realloc(final->arr,(final->length-1)*sizeof(int));        
        final->length--;
    }
    return final;
}

// int main(void)
// {
// struct linteger *int1 = vlintegerCreate();
// printf("Enter the digits separated by a space: \n");
// vlintegerRead(int1);
// vlintegerPrint(int1);
// assert(int1->arr[0] !=0);
//  char c;
//  scanf("%c", &c);
// struct linteger *int2 = vlintegerCreate();
// printf("Enter the digits separated by a space: \n");
// vlintegerRead(int2);
// vlintegerPrint(int2);
// assert(int2->arr[0] !=0);
// scanf("%c", &c);
// struct linteger *add = vlintegerAdd(int1, int2);
// printf("addition\n");
// vlintegerPrint(add);
// assert(add->arr[0] !=0);
// scanf("%c", &c);
// struct linteger *mult = vlintegerMult(int1, int2);
// printf("multiplication\n");
// vlintegerPrint(mult);
// assert(mult->arr[0] !=0);
// vlintegerDestroy(int1);
// vlintegerDestroy(int2);
// vlintegerDestroy(add);
// vlintegerDestroy(mult);
// }

