#include <stdio.h>


void sortArray(int a[]){

}

void printArray(int a[], int n){

}


int main (void){
    int a[] = {1, 56, 7, 734, 76, 4, 654, 346, 545, 346, 34, 577, 32345, 423, 23, 12, 5, 89, 4, 2, 687, 23, 5, 6, 7};
    printArray(a, sizeof(a)/sizeof(int));
    sortArray(a);
    printArray(a, sizeof(a)/sizeof(int));

}