#include<stdio.h>

int countOdd(int arr[], int n);
void reverse(int arr[], int n); 
void printArr(int arr[], int n);
int main() {
    int arr[] = {1, 2, 3, 4, 5, 6};
    reverse(arr, 6);
    printArr(arr, 6);
    return 0;
}
void printArr(int arr[], int n) {
    for(int i=0; i<n; i++) {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void reverse(int arr[], int n) {
    for(int i=0; i<n/2; i++) {
        int firstval =arr[i];
        int secondval = arr[n-i-1];
        arr[i] = secondval;
        arr[n-i-1] = firstval;
    }
}

