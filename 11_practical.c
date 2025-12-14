#include <stdio.h>
#include <stdlib.h>

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

void inorderRecursive(struct Node* root) {
    if (root == NULL) return;
    inorderRecursive(root->left);
    printf("%d ", root->data);
    inorderRecursive(root->right);
}

void preorderRecursive(struct Node* root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorderRecursive(root->left);
    preorderRecursive(root->right);
}

void postorderRecursive(struct Node* root) {
    if (root == NULL) return;
    postorderRecursive(root->left);
    postorderRecursive(root->right);
    printf("%d ", root->data);
}

#define MAX 100
struct Node* stack[MAX];
int top = -1;

void push(struct Node* node) {
    if (top < MAX - 1)
        stack[++top] = node;
}

struct Node* pop() {
    if (top >= 0)
        return stack[top--];
    return NULL;
}

int isEmpty() {
    return top == -1;
}

void inorderNonRecursive(struct Node* root) {
    struct Node* current = root;
    while (current != NULL || !isEmpty()) {
        while (current != NULL) {
            push(current);
            current = current->left;
        }
        current = pop();
        printf("%d ", current->data);
        current = current->right;
    }
}

void preorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    push(root);
    while (!isEmpty()) {
        struct Node* node = pop();
        printf("%d ", node->data);
        if (node->right) push(node->right);
        if (node->left) push(node->left);
    }
}

void postorderNonRecursive(struct Node* root) {
    if (root == NULL) return;
    struct Node* stack1[MAX];
    struct Node* stack2[MAX];
    int top1 = -1, top2 = -1;

    stack1[++top1] = root;

    while (top1 >= 0) {
        struct Node* node = stack1[top1--];
        stack2[++top2] = node;

        if (node->left)
            stack1[++top1] = node->left;
        if (node->right)
            stack1[++top1] = node->right;
    }

    while (top2 >= 0)
        printf("%d ", stack2[top2--]->data);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);
    root->right->left = createNode(6);
    root->right->right = createNode(7);

    printf("Recursive Traversals\n");
    printf("Inorder: ");
    inorderRecursive(root);
    printf("\nPreorder: ");
    preorderRecursive(root);
    printf("\nPostorder: ");
    postorderRecursive(root);

    printf("\n\nIterative Traversals\n");
    printf("Inorder: ");
    inorderNonRecursive(root);
    printf("\nPreorder: ");
    preorderNonRecursive(root);
    printf("\nPostorder: ");
    postorderNonRecursive(root);

    printf("\n");
    return 0;
}
