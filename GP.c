#include <stdio.h>
#include <math.h>

int main() {
    float a, r, n, sum;
    scanf("%f", &a);
    scanf("%f", &r);
    scanf("%f", &n);

    sum = (a * (1 - pow(r, n))) / (1 - r);
    printf("The sum of the GP series is: %f\n", sum);

    return 0;
}
