#include <stdio.h>

void map ( void * src , size_t n , size_t src_bytes , void * dest , size_t dest_bytes , void (* f )( void * , void *)){
    if ( n == 0)
    return ;
    f ( src , dest );

    map ( src + src_bytes , --n , src_bytes , dest + dest_bytes , dest_bytes , f );
}

void print (void *src, void *dst){
    printf("%d\n", *(int *) src);
    if (* (int* )src < 0){
        *(int*) dst = - *(int *)src;
    }
    else{
        *(int*) dst = *(int *)src;
    }
}

int main ( void ){
    int a[] = {1, -2, 3, -4};
    int b[4] = {};
    map (a , 4 , sizeof (int) , b , sizeof ( int ) , print);
    printf("B:");
    for(int i = 0; i < 4; i++){
        printf("%d ", b[i]);
    }

}