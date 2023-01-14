#include <stdio.h>
#include <string.h>
#include <assert.h>


void reduce(void *src, size_t n, size_t src_bytes, void *dest, void (*f) (void *, void *))
{
    if (n == 1)
    {
        f(src, dest);
        return;
    }
    reduce((char *)src+src_bytes, n-1, src_bytes, dest, f);
    f(src, dest);
 }

 void reverseConcatenate (void *lhs, void *rhs){
    strcat((char *)rhs, *(char **)lhs);
 }

 void concatenate (void *lhs, void *rhs){
    char temp[1000];
    temp[0] = '\0';
    strcat(temp , *(char **)lhs);
    strcat(temp, (char *)rhs);
    strcpy((char *)rhs, temp);
 }

int main(void)
 {

    int n = 10;
    char *words[] = {"The", "Quick", "Brown", "", "Fox", "Jumps", "Over", "The", "Lazy", "Dog"};
    char result[] = "TheQuickBrownFoxJumpsOverTheLazyDog";
    char backwards_result[] = "DogLazyTheOverJumpsFoxBrownQuickThe";    
    char answer[1000]; // you may assume that the length of the concatenated strings will not exceed 1000.
    answer[0] = '\0';
    reduce(words, n, sizeof(char *), answer, reverseConcatenate);
    assert(!strcmp(answer, backwards_result));  
    answer[0] = '\0';
    reduce(words, n, sizeof(char *), answer, concatenate);
    assert(!strcmp(answer, result));
    
    int t = 7;
    char *moreWords[] = {"Hello", " ", "", "", " ", "shutup", "c"};
    char result2[] = "Hello  shutupc";
    char backwards_result2[] = "cshutup  Hello";
    char answer2[1000];
    answer2[0] = '\0';
    reduce(moreWords, t, sizeof(char *), answer2, reverseConcatenate);
    assert(!strcmp(answer2, backwards_result2));
    answer2[0]= '\0';
    reduce(moreWords, t, sizeof(char *), answer2, concatenate);
    assert(!strcmp(answer2, result2));

    printf("reached2");

    return 0;

 }
