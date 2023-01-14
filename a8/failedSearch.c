#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

bool newSearch (int arr[], int len, int x){
    int BB = 0; int BA = len - 1;
    int Pos;
    
     printf("start with the range %d to %d\n", arr[BB], arr[BA]);
    if(x > arr[len-1] || x < arr[0]){
        printf("%d not in the range between %d and %d\n", x, arr[0], arr[len-1]);
        return false;
    }
    else if(len == 1){
        printf("%d was found in position %d\n", x, 0);
        return true;
    }
    else{
        while(BB < BA){
            Pos = (BB + ((float)(x - arr[BB])/(arr[BA] - arr[BB]))*(BA-BB));
            //Pos = (BB + ((x-arr[BB])*1.0/(arr[BA]-arr[BB])) * (BA-BB));
            printf("%d\n", Pos);
            if(arr[Pos] == x){
                printf("%d was found in position %d\n", x, Pos);
                return true;
            }
            else if(arr[Pos] < x){
                BB = Pos+1;
            }
            else{
                BA = Pos-1;
            }
            printf("move to search in the range between %d and %d\n", arr[BB], arr[BA]);
            }
        }

    return false;
}

// "start with the range %d to %d\n"
// "%d not in the range between %d and %d\n"
// "%d was found in position %d\n"
// "move to search in the range between %d and %d\n"


int main(void){
    int a[1] = {14};
     assert(!newSearch(a,1,10));
     printf("\n\n");
     assert(newSearch(a,1,14));
     printf("\n\n");
     int b[13] = {1,4,5,7,12,23,44,67,89,100,120,121,122};
     assert(!newSearch(b,13,0));
     printf("\n\n");
     assert(!newSearch(b,13,150));
     printf("\n\n");
     assert(newSearch(b,13,4));
     printf("\n\n");
     assert(newSearch(b,13,121));
     printf("\n\n");
     assert(newSearch(b,13,23));
     printf("\n\n");
    //  int c[20] = {-10,-4,5,7,12,23,44,67,89,100,120,121,122,200,210,222,300,301,303,500};
    //  assert(!newSearch(c,20,55));
    //  printf("\n\n");
    //  assert(newSearch(c,20,12));
    //  printf("\n\n");
    //  return 0;
}
