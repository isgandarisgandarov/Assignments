#include <stdio.h>

void swapStrings(char **destination, char **source);    /* I chose to use character pointers for strings not character arrays  */          
														/* because using built in functions was not allowed */
int main(){												/* also lengths of strings can be different */
    char *str1 = "Karabagh is Azerbaijan";				/* which makes using for loop for swapping strings impossible. */
    char *str2 = "Azerbaijan";

    printf("str1: %s, str2: %s\n",str1,str2);
    swapStrings(&str1, &str2);
    printf("str1: %s, str2: %s\n",str1,str2);

    return 0;
}

void swapStrings(char **destination, char **source){
    char *temp = *destination;
    *destination = *source;
    *source = temp;
}
