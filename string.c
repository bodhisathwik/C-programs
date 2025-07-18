#include <stdio.h>
#include <string.h>

int main() {
    char str[100];

    gets(str);
    int length = strlen(str);


    for (int i = length - 1; i >= 0; i--) {
        printf("%c", str[i]);
    }
    printf("\n");

    return 0;
}