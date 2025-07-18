#include <stdio.h>
#include <stdlib.h>
#define TABLE_SIZE 10

int hashTable[TABLE_SIZE];
int size = 0;

void initializeTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1;
    }
}

int hashFunction(int key) {
    return key % TABLE_SIZE;.
}

void insert(int key) {
    if (size == TABLE_SIZE) {
        printf("Hash table is full!\n");
        return;
    }
    int index = hashFunction(key);
    while (hashTable[index] != -1) {
        index = (index + 1) % TABLE_SIZE;
    }
    hashTable[index] = key;
    size++;
}
int search(int key) {
    int index = hashFunction(key);
    int startIndex = index;
    while (hashTable[index] != -1) {
        if (hashTable[index] == key) {
            return index;
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) {
            break;
        }
    }
    return -1;
}
void deleteKey(int key) {
    int index = search(key);
    if (index == -1) {
        printf("Key not found!\n");
        return;
    }
    hashTable[index] = -1;
    size--;
    index = (index + 1) % TABLE_SIZE;
    while (hashTable[index] != -1) {
        int tempKey = hashTable[index];
        hashTable[index] = -1;
        size--;
        insert(tempKey);
        index = (index + 1) % TABLE_SIZE;
    }

    printf("Key %d deleted successfully.\n", key);
}
void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] != -1) {
            printf("Index %d: %d\n", i, hashTable[i]);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}
int main() {
    initializeTable();
    int choice, key;
    while (1) {
        printf("\n1. Insert\n2. Search\n3. Delete\n4. Display\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;
            case 2:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int result = search(key);
                if (result != -1) {
                    printf("Key found at index %d\n", result);
                } else {
                    printf("Key not found\n");
                }
                break;
            case 3:
                printf("Enter the key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}