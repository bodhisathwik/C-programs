#include <stdio.h>
#include <stdlib.h>

// Define a node in the BST
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a value in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL) return createNode(value);
    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    return root;
}

// In-order traversal
void inOrderTraversal(struct Node* root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

// Pre-order traversal
void preOrderTraversal(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

// Post-order traversal
void postOrderTraversal(struct Node* root) {
    if (root != NULL) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        printf("%d ", root->data);
    }
}

// Search a value
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;
    if (key < root->data)
        return search(root->left, key);
    return search(root->right, key);
}

// Find minimum value node
struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL)
        root = root->left;
    return root;
}

// Find maximum value node
struct Node* findMax(struct Node* root) {
    while (root && root->right != NULL)
        root = root->right;
    return root;
}

// Delete a node
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Count total nodes
int countNodes(struct Node* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

// Height of BST
int height(struct Node* root) {
    if (root == NULL) return -1;
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

// Main program
int main() {
    struct Node* root = NULL;
    int choice, value;

    printf("Binary Search Tree Operations\n");

    do {
        printf("\n1. Insert\n2. In-Order\n3. Pre-Order\n4. Post-Order\n5. Search\n");
        printf("6. Find Min\n7. Find Max\n8. Delete\n9. Count Nodes\n10. Height\n11. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("In-Order: ");
            inOrderTraversal(root);
            printf("\n");
            break;
        case 3:
            printf("Pre-Order: ");
            preOrderTraversal(root);
            printf("\n");
            break;
        case 4:
            printf("Post-Order: ");
            postOrderTraversal(root);
            printf("\n");
            break;
        case 5:
            printf("Enter value to search: ");
            scanf("%d", &value);
            if (search(root, value))
                printf("Found!\n");
            else
                printf("Not found.\n");
            break;
        case 6:
            if (root)
                printf("Min value: %d\n", findMin(root)->data);
            else
                printf("Tree is empty.\n");
            break;
        case 7:
            if (root)
                printf("Max value: %d\n", findMax(root)->data);
            else
                printf("Tree is empty.\n");
            break;
        case 8:
            printf("Enter value to
