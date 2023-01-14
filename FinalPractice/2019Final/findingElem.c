#include <stdio.h>
#include <stdlib.h>

int *findElem(int *sorted_arr, int n, int elem){
    int *p = NULL;

    for(int i = 0 ;i < n; i++){
        if(sorted_arr[i] == elem){
            p = &sorted_arr[i];
            break;
        }
    }
    return p;
}

int main() {
    int p[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    printf("%d\n", *findElem(p, 9, 1));
    int arr[] = {3, 3, 3, 3, 3, 3, 3, 3, 3, 3};
    printf("%ld\n", findElem(arr, 9, 3) - arr);
    arr[0] = -1; arr[1] = 0;
    printf("%ld\n", findElem(arr, 9, 3) -arr);
}