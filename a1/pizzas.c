#include <stdio.h>
int main(void){
    int num_people, slices_per_pizza, slices_each, answer;
    scanf("%d %d %d", &num_people, &slices_per_pizza, &slices_each);
    answer =  num_people * slices_each / slices_per_pizza;
    printf("%d\n", num_people * slices_each % slices_per_pizza == 0 ? answer : answer +1);
    return 0;
}