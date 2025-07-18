#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int array[MAX_SIZE];
int front = -1;
int rear = -1;

int is_empty() {
    return front == -1;
}

int is_full() {
    return (rear + 1) % MAX_SIZE == front;
}

void enqueue(int data) {
    if (is_full()) {
        printf("Queue is full. Cannot enqueue %d.\n", data);
        return;
    }
    if (is_empty()) {
        front = 0;
    }
    rear = (rear + 1) % MAX_SIZE;
    array[rear] = data;
    printf("%d enqueued to the queue.\n", data);
}

int dequeue() {
    if (is_empty()) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    int data = array[front];
    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX_SIZE;
    }
    printf("%d dequeued from the queue.\n", data);
    return data;
}

void display() {
    if (is_empty()) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    int i = front;
    while (1) {
        printf("%d ", array[i]);
        if (i == rear) break;
        i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}