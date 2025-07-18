#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void addNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void deleteNode(int value) {
    if (head == NULL) {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    if (head->data == value) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        printf("Deleted %d from the list.\n", value);
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Deleted %d from the list.\n", value);
}

void displayList() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    addNode(10);
    addNode(20);
    addNode(30);
    addNode(40);

    printf("Initial Linked List:\n");
    displayList();

    printf("Deleting 20:\n");
    deleteNode(20);
    displayList();

    printf("Deleting 50 (not in the list):\n");
    deleteNode(50);
    displayList();

    printf("Deleting 10 (head node):\n");
    deleteNode(10);
    displayList();

    return 0;
}
