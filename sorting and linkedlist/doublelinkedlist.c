#include <stdio.h>
#include <stdlib.h>
typedef struct node snode;
struct node {
    int data;
    struct node *next;
    struct node *prev;
};
void display(snode *head);
snode* getNode(int value);
snode* createList(snode *head);
snode* insertNodeBeginning(snode* head);
snode* insertNodeAtPosition(snode* head, int pos);
snode* insertNodeEnd(snode* head);
snode* deleteNodeBeginning(snode* head);
snode* deleteNodeEnd(snode* head);
snode* deleteNodeAtPosition(snode* head, int pos);
void findElement(snode *head, int element);
snode* getNode(int value) {
    snode *p = (snode*) malloc(sizeof(struct node));
    p->data = value;
    p->next = NULL;
    p->prev = NULL;
    return p;
}
snode* createList(snode *head) {
    char s;
    snode *p, *q;
    int data;
    do {
        printf("Enter element: ");
        scanf("%d", &data);
        p = getNode(data);
        if (!head) {
            head = p;  
        } else {
            q = head;
            while (q->next) {
                q = q->next;  
            }
            q->next = p;
            p->prev = q;
        }
        printf("Do you want to continue adding nodes? (y/n): ");
        scanf(" %c", &s);  
    } while (s == 'y' || s == 'Y');
    return head;
}
snode* insertNodeBeginning(snode* head) {
    snode* newNode;
    int data;
    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);
    newNode->next = head; 
    if (head != NULL) {
        head->prev = newNode;
    }
    head = newNode;
    return head;
}
snode* insertNodeEnd(snode* head) {
    snode* newNode;
    snode* temp;
    int data;
    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (head == NULL) {
        return newNode;  
    }
    temp = head;
    while (temp->next != NULL) {
        temp = temp->next;  
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}
snode* insertNodeAtPosition(snode* head, int pos) {
    snode *newNode, *temp;
    int data, i;

    printf("Enter the data for the new node: ");
    scanf("%d", &data);
    newNode = getNode(data);

    if (pos == 1) {
        newNode->next = head;
        if (head != NULL) {
            head->prev = newNode;
        }
        return newNode;
    }
    temp = head;
    for (i = 1; i < pos - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(newNode);
        return head;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    
    return head;
}
snode* deleteNodeBeginning(snode* head) {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }
    snode* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    printf("\nNode deleted from the beginning.\n");
    return head;
}
snode* deleteNodeEnd(snode* head) {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }
    if (head->next == NULL) {
        free(head);
        printf("\nNode deleted from the end.\n");
        return NULL;
    }
    snode *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    free(temp);
    printf("\nNode deleted from the end.\n");
    return head;
}
snode* deleteNodeAtPosition(snode* head, int pos) {
    if (head == NULL) {
        printf("\nList is empty. Nothing to delete.\n");
        return head;
    }
    snode *temp = head;
    if (pos == 1) {
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        free(temp);
        printf("\nNode deleted at position %d.\n", pos);
        return head;
    }
    int i;
    for (i = 1; i < pos && temp != NULL; i++) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("\nInvalid position! Node does not exist.\n");
        return head;
    }
    temp->prev->next = temp->next;
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    free(temp);

    printf("\nNode deleted at position %d.\n", pos);
    return head;
}

void display(snode *head) {
    snode *p;
    if (!head) {
        printf("\nList is empty\n");
    } else {
        p = head;
        printf("\nList of elements are: ");
        while (p) {
            printf("%5d", p->data);
            p = p->next;
        }
        printf("\n");
    }
}

void findElement(snode *head, int element) {
    snode *p;
    p = head;
    while (p != NULL) {
        if (p->data == element) {
            printf("Element found\n");
            return;
        }
        p = p->next;
    }
    printf("Element not found\n");
}

int main() {
    int choice, pos, element;
    snode *head = NULL;
    
    do {
        printf("\nEnter a number between 1 and 10 to choose an option:\n");
        printf("1. Create linked list\n");
        printf("2. Insert node at the beginning\n");
        printf("3. Insert node at the end\n");
        printf("4. Insert node at the given position\n");
        printf("5. Delete node at the beginning\n");
        printf("6. Delete node at the end\n");
        printf("7. Delete node at the given position\n");
        printf("8. Find element\n");
        printf("9. Display\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Creating Linked List...\n");
                head = createList(head);  
                break;
            case 2:
                printf("Insert node at the beginning\n");
                head = insertNodeBeginning(head); 
                break;
            case 3:
                printf("Insert node at the end\n");
                head = insertNodeEnd(head);
                break;
            case 4:
                printf("Insert node at the given position\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = insertNodeAtPosition(head, pos);
                break;
            case 5:
                printf("Delete node at the beginning\n");
                head = deleteNodeBeginning(head);
                break;
            case 6:
                printf("Delete node at the end\n");
                head = deleteNodeEnd(head);
                break;
            case 7:
                printf("Delete node at the given position\n");
                printf("Enter the position: ");
                scanf("%d", &pos);
                head = deleteNodeAtPosition(head, pos);
                break;
            case 8:
                printf("Find element\n");
                printf("Enter the element to find: ");
                scanf("%d", &element);
                findElement(head, element);
                break;
            case 9:
                printf("Display\n"); 
                display(head);
                break;
            case 10:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please choose a number between 1 and 10.\n");
        }
    } while (choice != 10);
    
    return 0;   
}