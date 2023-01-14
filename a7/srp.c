#include <stdio.h>
#include <assert.h>
#include <string.h>


int shortestRepeatingPrefix(char s[]){
    int true;

    for(int i = 1 ; i < strlen(s); i++){
        true = 1;
        for(int j = i; j < strlen(s); j++){
            if(s[j%i] != s[j]){
                true = 0;
                break;
            }
        }
    
        if(true){
            return i;
        }
    }
    return strlen(s);
}


// int main (void){
//     char s1 [] = "hihihihi";
//     assert(shortestRepeatingPrefix(s1) == 2);

//     char s2 [] = "aaaaa";
//     assert(shortestRepeatingPrefix(s2) == 1);

//     char s3 [] = "qwerty";
//      assert(shortestRepeatingPrefix(s3) == 6);

//      char s4 [] = "";
//      assert(shortestRepeatingPrefix(s4) == 0);

//      return 0;
// }