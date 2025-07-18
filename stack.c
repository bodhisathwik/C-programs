#include<stdio.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int va) {
    if (top = MAX-1) {
        printf("Stack Overflow\n");
    }else {
        top++;
        stack[top]=va;
        printf("%d pushed to stack\n",va);
    }
}
int pop() {
    if (top=-1){
        printf("Stack Underflow\n");
    } else {
        int val=stack[top];
        top--;
        printf("Popped %d from stack\n");
        return val;
    }
}
void display() {
    if (top = -1) {
        printf("Stack is empty\n");
        } else {
            printf("Stack elements: ");
            for (int i = top; i >= 0; i--) {
                printf("%d ", stack[i]);
            }
            printf("\n");
        }
}
int main()
{
    int elements, value;
    while(1){
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &elements);
    }
    switch(elements){
        case 1:
        printf("Enter value to push: ");
        scanf("%d", &value);
        push(value);
        break;
        case 2:
        pop();
        break;
        case 3:
        display();
        break;
        case 4:
        exit(0);
        default:
        printf("Invalid choice\n");
    }
}
}