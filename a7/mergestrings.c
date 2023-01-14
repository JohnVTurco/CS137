#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


char* merge (char* s1, char* s2){
    char* s3 = malloc((strlen(s1) + strlen(s2) + 2) *sizeof(char));
    int finalCounter = 0;
    int firstCounter = 0;
    int secondCounter = 0;
    while(s1[firstCounter] && s2[secondCounter]){
        
        if(finalCounter != 0){
            s3[finalCounter] = ' ';
            finalCounter++;
        }
        
        while(s1[firstCounter] != ' ' && s1[firstCounter]){
            s3[finalCounter] = s1[firstCounter];
            finalCounter++;
            firstCounter++;
        }
        if(s1[firstCounter] == ' '){
            firstCounter++;
        }

        s3[finalCounter] = ' ';
        finalCounter++;

        while(s2[secondCounter] != ' ' && s2[secondCounter]){
            s3[finalCounter] = s2[secondCounter];
            finalCounter++;
            secondCounter++;

        }
        if(s2[secondCounter] == ' '){
            secondCounter++;
        }

        //printf("first: %d\nsecond: %d\nfinal: %d\n", firstCounter, secondCounter, finalCounter);
    }

    s3[finalCounter] = ' ';
    finalCounter++;

    if(firstCounter < strlen(s1)){
        while(s1[firstCounter]){
            s3[finalCounter] = s1[firstCounter];
            finalCounter++;
            firstCounter++;
        }

    }
    
    if(secondCounter < strlen(s2)){
        while(s2[secondCounter]){
            s3[finalCounter] = s2[secondCounter];
            finalCounter++;
            secondCounter++;
        }
    }
    s3[finalCounter] = '\0';

    return s3;
}



int main(void)
{
    
    char s1[] = "The brown jumps the dog";
    char s2[] = "quick fox over lazy";

     char *s = merge(s1, s2);
     //printf("%s\n", s);
     assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
     free(s);
     
     char s3[] = "the brown";
     char s4[] = "quick fox is sleeping today";
     s = merge(s3,s4);
     assert(!strcmp(s, "the quick brown fox is sleeping today"));
     free(s);

     char* s5 = "happy to you";
     char* s6 = "birthday";
     s = merge(s5,s6);
     assert(!strcmp(s, "happy birthday to you"));
     free(s);

    char* s7 = "a b c d";
    char* s8 = "a";
    s = merge(s7, s8);
    assert(!strcmp(s, "a a b c d"));
    free(s);


     return 0;
}