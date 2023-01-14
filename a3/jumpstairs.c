#include <stdio.h>
#include <assert.h>

int jump_stair_v1(int n){
    if(n == 1){
        return 1;
    }
    else if(n == 2){
        return 2;
    }

    return jump_stair_v1(n-1) + jump_stair_v1(n-2);
}

int jump_stair_v2(int n){
    if(n == 1 || n == 3){
        return 1;
    }
    else if(n<=6){
        return 2;
    }

    return jump_stair_v2(n-3) + jump_stair_v2(n-6);

}

int jump_stair_v3(int n){
    if(n == 3 || n == 6 || n == 9){
        return 1;
    }
    else if(n < 9){
        return 0;
    }
    return jump_stair_v3(n-6) + jump_stair_v3(n-9);
}
