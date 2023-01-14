#include <stdio.h>
#include <assert.h>
#include "event.h"


int freetime (struct event schedule[], int n, int hour, int min){
    int startTime, endTime;
    for(int i = 0; i < n; i++){
        startTime = schedule[i].start.hour * 60 + schedule[i].start.minute;
        endTime = schedule[i].end.hour * 60 + schedule[i].end.minute;
        if(hour * 60 + min >= startTime && hour * 60 + min < endTime){
            return 0;
        }
        startTime = 0;
        endTime = 0;
    }
    return 1;
}
