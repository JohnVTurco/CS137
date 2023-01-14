#include <stdio.h>
#include <assert.h>

typedef struct Point{
    int x;
    int y;
}point;

typedef struct Rectangle{
    point bottomLeft;
    int width;
    int height;
}rectangle;

rectangle intersection(rectangle rects[], int n){
    rectangle zero = {{0, 0}, 0, 0};
    int minx, maxx, miny, maxy;
    minx = rects[0].bottomLeft.x;
    maxx = minx + rects[0].width;
    miny = rects[0].bottomLeft.y;
    maxy = miny + rects[0].height;

    for(int i = 0; i < n; i++){
        if(rects[i].bottomLeft.x > minx){
            minx = rects[i].bottomLeft.x;
        }
        if(rects[i].bottomLeft.x + rects[i].width < maxx){
            maxx = rects[i].bottomLeft.x + rects[i].width;
        }
        if(rects[i].bottomLeft.y > miny){
            miny = rects[i].bottomLeft.y;
        }
        if(rects[i].bottomLeft.y + rects[i].height < maxy){
            maxy = rects[i].bottomLeft.y + rects[i].height;
        }
    }

    if(maxy < miny || maxx < minx){
        return zero;
    }
    rectangle final = {{minx, miny}, maxx - minx, maxy - miny};
    return final;

}
