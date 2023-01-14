#include <stdio.h>
#include <stdbool.h>

bool arrayCompare(int n, int arr[n][n]){
    bool same = true;
    int sumRow = 0, sumCol = 0;
    for(int i = 0; i < n; i++){
        for(int k = 0; k < n; k++){
            sumRow += arr[i][k];
            sumCol += arr[k][i];
        }
        if(sumRow != sumCol){
            return false;
        }
        sumRow = 0;
        sumCol = 0;
    }
}

void arrayShift (int n, int arr[n], int shift){
    int temp;
    for(int i = 0; i < shift; i++){
        temp = arr[n-1];
        for(int k = n-1; k > 0; k--){
            arr[k] = arr[k-1];
           
        }
        arr[0] = temp;
    }
}

int main(void){
    // int array[4][4] = {{1, 2 ,3, 4} , 
    //                    {2, 2, 2, 2},
    //                    {3, 2, 3, 4},
    //                    {4, 2, 4, 4}};

    // bool same = arrayCompare(4, array);
    // if(same){
    //     printf("Same");
    // }
    // else{
    //     printf("different");
    // }

    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    arrayShift(9, array, 5);
    for(int i = 0 ; i < 9; i++){
        printf("%d ", array[i]);
    }
}