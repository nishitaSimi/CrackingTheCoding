#include <cstring>
#include <iostream>
#include <stdio.h>

void reverse(char *str)
{
    char *start = str, *end = str + strlen(str) - 1;

    while (start < end) {
        char tmp = *start;
        *start++ = *end;
        *end-- = tmp;
    }
}

int main(){
    char input[]  = "Piano";
    reverse(input);
    printf("Reversed string : %s \n", input);
    return 0;
}
