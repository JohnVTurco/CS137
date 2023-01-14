#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

bool is_palindrome(char *s){
    int n = strlen(s);

    if(n == 1 || n == 0){
        return false;
    }

    for(int i = 0; i < (n-1)/2; i++){
        if(s[i] != s[n-i-1]){
            return false;
        }
    }
    return true;
}

bool is_semidrome(char *s){

    char *t = malloc((strlen(s)+ 1) * sizeof(char));
    int i = 0;
    strcpy(t, s);
    char current;

    if(is_palindrome(s)){
        free(t);
        return true;
    }
   
    while(s[i]){
        current = t[i+1];
        t[i+1] = '\0';
        
        if(is_palindrome(t) && strlen(t) >= 2){
            char *pointer = s;
            pointer += i + 1;

            if(is_semidrome(pointer)){
                free(t);
                return true;
            }
        }

        t[i+1] = current;
        i++;
    }

    free(t);
    return false;
}

int main (void){
    
    assert(is_semidrome("popeye"));
    assert(is_semidrome("racecar"));
    assert(!is_semidrome("aab"));
    assert(!is_semidrome(""));
    assert(is_semidrome("dadmomracecar"));
    assert(is_semidrome("popopeye"));
    assert(is_semidrome("gg"));
    return 0;
}