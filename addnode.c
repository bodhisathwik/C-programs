#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

int main() {

    struct Node* firstNode = (struct Node*)malloc(sizeof(struct Node));
    firstNode->data = 10;
    firstNode->next = NULL;
    struct Node* secondNode = (struct Node*)malloc(sizeof(struct Node));
    secondNode->data = 20;
    secondNode->next = NULL; 
    firstNode->next = secondNode;
    printf("Linked List:\n");
    struct Node* temp = firstNode;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");


    free(firstNode);
    free(secondNode);

    return 0;
}
