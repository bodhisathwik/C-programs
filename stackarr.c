//c program for stack operation using arrays using structure
#include <stdio.h>
#include <stdlib.h>
#define MAX 10
struct stack
{
    int item[MAX];
    int top;
};
void push(struct stack *s);
void pop(struct stack *s);
void display(struct stack *s); 
int main()
{
    struct stack s;
    s.top = -1;
    int choice;
    while (1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            push(&s);
            break; 
        case 2:
            pop(&s);
            break;
        case 3:
            display(&s);
            break;
        case 4:
            exit(0);
        default:
            printf("Invalid choice\n");
        }
    }
    return 0;
}
void push(struct stack *s)
{
    int item;
    if (s->top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Enter the item to be pushed: ");
        scanf("%d", &item);
        s->top++;
        s->item[s->top] = item;
    }
}
void pop(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack Underflow\n");
    }
    else
    {
        printf("Element popped = %d\n", s->item[s->top]);
        s->top--;
    }
}
void display(struct stack *s)
{
    if (s->top == -1)
    {
        printf("Stack is empty\n");
    }
    else
    {
        printf("Stack elements are:\n");
        for (int i = s->top; i >= 0; i--)
        {
            printf("%d\n", s->item[i]);
        }
    }
}
