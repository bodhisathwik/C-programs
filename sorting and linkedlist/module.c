//create a program file with the name module.c that contains methods for performing arthimatic operations add, sub, mul and div. you methods should take two parameters and should return a value.
//create another program file arthimatic.c in this file accept two integer values and perform arthimatic operations on these two numbers by calling the methods present in module.c file.
#include <stdio.h>
int add(int a, int b) {
    return a + b;
}
int sub(int a, int b) {
    return a - b;
}
int mul(int a, int b) {
    return a * b;
}
int div(int a, int b) {
    if (b == 0) {
        printf("Error\n");
        return 0; 
    }
    return a / b;
}