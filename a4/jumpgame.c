#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool canComplete (int i, int arr[], int len){

    if(arr[i] == 0){
        return false;
    }

    for(int j = 1; j <= arr[i]; j++){
        if(i + j == len - 1){
            return true;
        }
        else if(i + j < len - 1){
            if (canComplete(i + j, arr, len)){
                return true;
            }

        }

    }
    return false;  
}
