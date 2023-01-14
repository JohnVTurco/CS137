#include <stdio.h>

struct tod{
    int hours; //0 <= hours <= 23 || (hours == 24 && minutes == 0)
    int minutes; //0 <= minutes <= 59
};

struct event {
    struct tod start; //(start.hours <= end.hours) &&
    struct tod end; //(start.hours < end.hours || start.minutes <= end.minutes)
};

void free_time(struct event sched[], int n){
    int timeFree = 24*60;
    int timeStart = 0, timeEnd = 0, timeSize = 0;

    for(int i = 0 ; i < n; i++){
        timeStart = (sched[i].start.hours*60 + sched[i].start.minutes);
        timeEnd = (sched[i].end.hours*60 + sched[i].end.minutes);
        timeSize = timeEnd - timeStart;
        timeFree -= timeSize;
        timeSize = 0; timeEnd = 0, timeStart = 0;
    }

    printf("%d hour and %d minutes\n", timeFree/60, timeFree%60);
}

int main(void){
    struct event busy[1] = {{{0, 0},{24,0}}};
    free_time(busy,1);
    struct event sleeping[2] = { {{0,0}, {6,30}}, {{20,10}, {24,0}}};
    free_time(sleeping,2);
    struct event poor_pluralization_is_okay[1] = {{{0, 0},{22,59}}};
    free_time(poor_pluralization_is_okay, 1);
    return 0;
}