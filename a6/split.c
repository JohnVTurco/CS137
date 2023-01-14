#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int **split(int a[], int n, int p, int *len1, int *len2){
    
    int ar1Count = 0, ar2Count = 0;
    int *arrayOne = malloc(0);
    int *arrayTwo = malloc(0);
    *len1 = 0;
    *len2 = 0;
    
    for(int i = 0; i < n; i++){
        if(a[i] <= p){
            ar1Count++;
            arrayOne = (int *) realloc(arrayOne, ar1Count *sizeof(int));
            arrayOne[ar1Count -1] = a[i];
            *len1 +=1;
        }
        else{
            ar2Count++;
            arrayTwo = (int *) realloc(arrayTwo, ar2Count * sizeof(int));
            arrayTwo[ar2Count - 1] = a[i];
            *len2+=1;
        }
    }

    int **arrayThree = malloc(2*sizeof(int*));
    arrayThree[0] = &arrayOne[0]; 
    arrayThree[1] = &arrayTwo[0];

    return arrayThree;
}

// int main (void){
//     int a[] = {9,3,2,6,-1,3,6,6,7,8,5,2,3,4,1,0};
//      int n = sizeof(a)/sizeof(a[0]);
//      int n1,n2;
//      int **ans = split(a,n,5,&n1, &n2);
//      assert(n1==10);
//      assert(n2==6);
//      printf("First Array\n");
//      for (int i=0; i<n1; i++){
//      printf("%d\n",ans[0][i]);
//      }
//      printf("Second Array\n");
//      for (int i=0; i<n2; i++){
//      printf("%d\n",ans[1][i]);
//      }
//      free(ans[1]);
//      free(ans[0]);
//      free(ans);

//      ans = split(a,n,-10,&n1, &n2);
//      assert(n1==0);
//      assert(n2==n);
//      printf("First Array\n");
//      for (int i=0; i<n1; i++){
//      printf("%d\n",ans[0][i]);
//      }
//      printf("Second Array\n");
//      for (int i=0; i<n2; i++){
//      printf("%d\n",ans[1][i]);
//      }  
//      free(ans[1]);
//      free(ans[0]);
//      free(ans);

//      return 0;
// }