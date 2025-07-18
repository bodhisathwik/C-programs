#include <stdio.h>

int main() {
    int n, i;
    float hp;
    scanf("%d", &n);

    printf("hP: \n");
    for (i = 1; i <= n; i++) {
        switch (i) {
            case 1:
            hp = 1.0;
            break;
            case 2:
            hp = 1.0 / 2;
            break;
            case 3:
            hp = 1.0 / 3;
             break;
            case 4:
            hp = 1.0 / 4;
            break;
            case 5:
            hp = 1.0 / 5;
            break;
            default:
            hp = 1.0 / i;
            break;
        }
        printf("%f ", hp);
    }

    printf("\n");
    return 0;
}
