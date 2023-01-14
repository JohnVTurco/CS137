#include <stdio.h>
#include <math.h>
#include <assert.h>

void map(void *src, size_t n, size_t src_bytes, void *dest, size_t dest_bytes, void (*f) (void *, void *)) {
    if (n == 0)
        return;
    f(src, dest);// f writes to dest itself:
    map(src + src_bytes, --n, src_bytes, dest + dest_bytes, dest_bytes, f);
 }

 void reduce(void *src, size_t n, size_t src_bytes, void *dest, void (*f) (void *, void *)) {
    if (n == 1) {
        f(src, dest);
        return;
    }
    reduce((char *)src + src_bytes, n - 1, src_bytes, dest, f);
    f(src, dest);
 }


 typedef struct Vector {
    double x, y, z;
 } Vector;

 void EuclideanNorm(void *src, void *dest){
    Vector *v = (Vector *) src;
    double norm = sqrt(v->x * v->x + v->y * v->y + v->z * v->z);
    *(double *) dest = norm;
 }

 void sum(void *src, void *dest) {
    *(double *) dest = *(double *) dest + *(double *)src;
    
 }

 int main(void) {
    Vector a[2] = { {1, 0, 1}, {2, 0, 3} };
    double b[2] = { 0 };
    double res = 0;
    map(a, 2, sizeof(Vector), b, sizeof(double), EuclideanNorm);
    reduce(b, 2, sizeof(double), &res, sum);
    assert(fabs(res - 5.019765)<= 0.000001);
    
    Vector c[3] = { {1 ,2 ,3 }, {0, 222 ,0}, {9, 99 ,84}};
    double d[3] = {0};
    double res2 = 0;
    map(c, 3, sizeof(Vector), d, sizeof(double), EuclideanNorm);
    reduce(d, 3, sizeof(double), &res2, sum);
    assert(fabs(res2 - 355.8877292)<= 0.000001);
    
    printf("reached5");

    return 0;
 }