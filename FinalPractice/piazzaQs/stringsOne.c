#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char *reversedString(char *string){
    int counter = 0;
    char *newString = malloc((strlen(string) + 1) * sizeof(char));
    
    for(int i = strlen(string); i > 0; i--){
        newString[strlen(string) - i] = string[i-1];
    }

    newString[strlen(string)+1] = '\0';
    return newString;
}

char *repeatedString(char *string, int n){
    char *newString = calloc((strlen(string) * n + 1), sizeof(char));
    
    for(int i = 0; i < n; i++){
        strcat(newString, string);
    }
    //newString[(strlen(string) * n) -1] = '\0';
    return newString;
    
}
        

int main(void){
    char *s = "hello";
    char *t = repeatedString(s, 5);

    int i = 0;
    while(t[i]){
        printf("%c", t[i]);
        i++;
    }
    
    
}