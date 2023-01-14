#include <stdio.h>
#include <math.h>
#include <assert.h>
#define PI acos(-1)

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
    double areaOne = 0, areaTwo;
    double intervalSize = (b-a) / n;

    for(int i = 0; i < n; i++){
            areaOne += (f(a+ intervalSize*i) + f(a + intervalSize*(i+1))) / 2 * intervalSize;
        }
        areaTwo = areaOne;

    do{
        areaOne = areaTwo, areaTwo = 0;

        intervalSize /= 2;
        n*=2;

        for(int i = 0; i < n; i++){
            areaTwo += (f(a+ intervalSize*i) + f(a + intervalSize*(i+1))) / 2 * intervalSize;
        }
        
    }while(fabs(areaTwo - areaOne) > epsilon);  

    return areaTwo;
}
