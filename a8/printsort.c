#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printsorted(char* word, int len){
    int currentChar;
    int maxFrequency = 1;
    int a[26] = {0};

    for(int i = 0; i < len; i++){
        currentChar = word[i];

        if(currentChar-97 >= 0 && currentChar-97 <= 25){
            a[currentChar-97]++;
        }
        
    }

    while(maxFrequency != 0){
        maxFrequency = 0;
        for(int j = 0; j < 26; j++){
            if(a[j] > maxFrequency){
                maxFrequency = a[j];
            }
        }
        for(int k = 0; k < 26; k++){
            if(a[k] == maxFrequency){
                a[k] = 0;
                for(int t = 0; t < maxFrequency; t++){
                    printf("%c", k+97);
                }
            }
        }
    }
    printf("\n");
    return;

}


int main(void){
    printsorted("hello world!!!", strlen("hello world!!!"));
    printsorted("hhhgggdddddeeeeebbccccccaaaaassssrrrr", 38);
    char *s1 = "abb ccc";
    printsorted(s1, strlen(s1));
    char *s2 = "";
    printsorted(s2, strlen(s2));
    char *s3 = "a        kkkkkkkkk";
    printsorted(s3, strlen(s3));
    char *s4 = "a b ccc e d h g ggg k z";
    printsorted(s4, strlen(s4));
    char *s5 = "??!! z a z z a b c b a";
    printsorted(s5, strlen(s5));
    return 0;
}