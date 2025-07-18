#include<stdio.h>
#include<stdlib.h>
struct stack
{
    int size;
    int top;
    int *arr;

};
struct stack s1;
void push(int);
int pop();
void display();
int main()
{
    s1.top=-1;
    scanf("%d",&s1.size);
    s1.arr=(int *)malloc(s1.size*sizeof(int));
    int opt, n, x;
    while(1)
    {
        printf("\n1. Push \n2. Pop \n3. Display \n4. Exit \nEnter your choice: ");
        scanf("%d", &opt);
        switch(opt)
        {
            case 1:
            printf("\nEnter a value");
            scanf("%d", &n);
            push(n);
            break;
            case 2:
            x=pop();
            if(x!=-1)
            {
                printf("\n%d is popped", x);
            }
            break;
            case 3:
            display();
            break;
            case 4:
            exit(0);
            default:
            printf("\nWrong choice, try again");
        }
    }
    return 0;
}
void push(int data)
{
    if(s1.top==s1.size-1)
    {
        printf("\nStack is full no insertion possible");
    }
    else
    {
        s1.top++;
        s1.arr[s1.top]=data;
    }
}
int pop()
{
    int x;
    if(s1.top==-1)
    {
        printf("\nStack is empty no deletion possible");
        return -1;
    }
    else
    {
        x=s1.arr[s1.top];
        s1.top--;
        return x;
    }
}
void display()
{
    int i;
    for(i=s1.top; i>=0; i--)
     printf("\n%d", s1.arr[i]);
}
