#include <stdio.h>

void reduce ( void * src , size_t n , size_t src_bytes , void * dest , void (* f ) ( void * , void *)){
    if ( n == 1)
    {
        f ( src , dest );
        return ;
    }
    reduce ( src + src_bytes , n - 1 , src_bytes , dest , f ); 
    f ( src , dest );
}

void sum ( void * lhs , void * rhs ){
    if(*(int *) lhs > 0){
        *(int *)rhs += 1;
    }
}

int main ( void ){
    int a [] = { 5 , -4 , -3 , 2 , 1 };
    int answer = 0;
    reduce (a , 5 , sizeof ( int ) , &answer , sum );
    printf("%d", answer);
    // answer = 120 (5*4*3*2*1).
    int res = 0;
   // reduce (a , 5 , sizeof ( int ) , & res , sum_sqr );
    // res = 55 (5^2 + 4^2 + 3^2 + 2^2 + 1^2)).
}
