#include <stdio.h>
#include <string.h>

int lengthOfLastWord(char *s) {
    int len = strlen(s);
    int count = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (s[i] == ' ' && count == 0) {
            continue;
        }
        else if (s[i] == ' ' && count > 0) {
            break;
        } else {
            count++;
        }
    }

    return count;
}

int main() {
    char s[100];
    fgets(s, sizeof(s), stdin);
        s[strcspn(s, "\n")] = 0;

    int result = lengthOfLastWord(s);
    printf("%d\n", result);

    return 0;
}
