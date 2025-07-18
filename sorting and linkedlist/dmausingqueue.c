#include<stdio.h>
#include<stdlib.h>

struct queue {
    int size;
    int front;
    int rear;
    int *arr;
};

struct queue q1;

void enqueue(int);
int dequeue();
void display();

int main() {
    q1.front = -1;
    q1.rear = -1;
    
    scanf("%d", &q1.size);
    q1.arr = (int *)malloc(q1.size * sizeof(int));
    
    int opt, n, x;
    while(1) {
        printf("\n1. Enqueue \n2. Dequeue \n3. Display \n4. Exit \nEnter your choice: ");
        scanf("%d", &opt);
        
        switch(opt) {
            case 1:
                printf("\nEnter a value: ");
                scanf("%d", &n);
                enqueue(n);
                break;
            case 2:
                x = dequeue();
                if(x != -1) {
                    printf("\n%d is dequeued", x);
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

void enqueue(int data) {
    if(q1.rear == q1.size - 1) {
        printf("\nQueue is full, no insertion possible");
    }
    else {
        if(q1.front == -1) {
            q1.front = 0;
        }
        q1.rear++;
        q1.arr[q1.rear] = data;
    }
}

int dequeue() {
    int x;
    if(q1.front == -1 || q1.front > q1.rear) {
        printf("\nQueue is empty, no deletion possible");
        return -1;
    }
    else {
        x = q1.arr[q1.front];
        q1.front++;
        if(q1.front > q1.rear) {
            q1.front = q1.rear = -1;
        }
        return x;
    }
}

void display() {
    int i;
    if(q1.front == -1 || q1.front > q1.rear) {
        printf("\nQueue is empty");
        return;
    }
    for(i = q1.front; i <= q1.rear; i++) {
        printf("\n%d", q1.arr[i]);
    }
}
