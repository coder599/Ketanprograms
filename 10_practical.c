#include <stdio.h>
#include <stdlib.h>

#define MAX 100
int treeArray[MAX];

void insertArrayTree(int data, int index) {
    if (index >= MAX) {
        printf("Array index out of bounds\n");
        return;
    }
    treeArray[index] = data;
}

void displayArrayTree(int index) {
    if (index >= MAX || treeArray[index] == 0)
        return;
    printf("%d ", treeArray[index]);
    displayArrayTree(2 * index + 1); 
    displayArrayTree(2 * index + 2);
}


struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct Node* insertBST(struct Node* root, int data) {
    if (root == NULL)
        return createNode(data);
    if (data < root->data)
        root->left = insertBST(root->left, data);
    else if (data > root->data)
        root->right = insertBST(root->right, data);
    return root;
}

void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

struct Node* findMin(struct Node* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Leaf Node
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        // One Child
        else if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        // Two Children
        else {
            struct Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    for (int i = 0; i < MAX; i++){
        treeArray[i] = 0;
    }

    insertArrayTree(1, 0); 
    insertArrayTree(2, 1); 
    insertArrayTree(3, 2); 
    insertArrayTree(4, 3); 
    insertArrayTree(5, 4); 

    printf("Traversal array-based tree: ");
    displayArrayTree(0);
    printf("\n\n");

    struct Node* root = NULL;
    root = insertBST(root, 50);
    root = insertBST(root, 30);
    root = insertBST(root, 70);
    root = insertBST(root, 20);
    root = insertBST(root, 40);
    root = insertBST(root, 60);
    root = insertBST(root, 80);

    printf("Before deletion:\n");
    inorder(root);
    printf("\n");

    printf("After deletion:\n");
    root = deleteNode(root, 20);
    inorder(root);
    printf("\n");

    root = deleteNode(root, 30);
    inorder(root);
    printf("\n");

    root = deleteNode(root, 50);
    inorder(root);
    printf("\n");

    return 0;
}
