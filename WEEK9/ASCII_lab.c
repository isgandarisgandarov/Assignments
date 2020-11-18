#include <stdio.h>

void function(char *source, char *integers, char *nonIntegers);

int main(){
    char source[] = "abc123def99!";
    char integers[256];
    char nonIntegers[256];
    function(source, integers, nonIntegers);
    printf("%s\n", source);
    printf("%s\n", integers);
    printf("%s\n", nonIntegers);

}

void function(char *source, char *integers, char *nonIntegers){
    int i = 0, IndexOfInt = 0, IndexOfNonint = 0;
    for ( ; source[i] != '\0'; i++){
        if (source[i] >= 48 && source[i] <= 57){
            integers[IndexOfInt] = source[i];
            IndexOfInt++;
        }
        else{
            nonIntegers[IndexOfNonint] = source[i];
            IndexOfNonint++;
        }
        integers[IndexOfInt] = '\0';
        nonIntegers[IndexOfNonint] = '\0';
    }
}
