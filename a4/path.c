#include <stdio.h>
#include <assert.h>

int helper(int m, int n, int x, int y, int a[m][n]){
    if(x == 0 && y == 0){
        return 1;
    }
    if(x > 0 && a[x-1][y] == 1 && helper(m, n, x-1, y, a)){
        return 1;

    }
    if(y > 0 && a[x][y-1] == 1 && helper(m, n, x, y-1, a)){
        return 1;
    }
    return 0;
}

int monotonePath(int m, int n, int a[m][n]){
    helper(m, n, m-1, n-1, a);
}

 