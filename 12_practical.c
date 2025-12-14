#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int height;
    struct Node *left;
    struct Node *right;
} Node;

int totalRotations = 0;

int height(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (n->height);
}

int max(int a, int b)
{
    return ((a > b) ? a : b);
}

int getBalance(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return (height(n->left) - height(n->right));
}

Node *newNode(int data)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node *rightRotate(Node *y)
{
    printf("Right Rotation performed.\n");
    totalRotations++;

    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = (1 + max(height(y->left), height(y->right)));
    x->height = (1 + max(height(x->left), height(x->right)));

    return x;
}

Node *leftRotate(Node *x)
{
    printf("Left Rotation performed.\n");
    totalRotations++;

    Node *y = x->right;
    Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = (1 + max(height(x->left), height(x->right)));
    y->height = (1 + max(height(y->left), height(y->right)));
    return y;
}

Node *insertNode(Node *node, int data)
{
    if (node == NULL)
    {
        return (newNode(data));
    }

    if (data < node->data)
    {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data)
    {
        node->right = insertNode(node->right, data);
    }
    else
    {
        return node;
    }

    node->height = (1 + max(height(node->left), height(node->right)));

    int balance = getBalance(node);

    // LL
    if ((balance > 1) && (data < node->left->data))
    {
        printf("Not AVL -> LL Case\n");
        return (rightRotate(node));
    }

    // RR
    if ((balance < -1) && (data > node->right->data))
    {
        printf("Not AVL -> RR Case\n");
        return (leftRotate(node));
    }

    // LR
    if ((balance > 1) && (data > node->left->data))
    {
        printf("Not AVL -> LR Case\n");
        node->left = leftRotate(node->left);
        return (rightRotate(node));
    }

    // RL
    if ((balance < -1) && (data < node->right->data))
    {
        printf("Not AVL -> RL Case\n");
        node->right = rightRotate(node->right);
        return (leftRotate(node));
    }

    return node;
}

void checkAVL(Node *root)
{
    int balance = getBalance(root);
    if ((balance >= -1) && (balance <= 1))
    {
        printf("Tree is AVL\n");
    }
    else
    {
        printf("Tree is NOT AVL\n");
    }
}

void inorder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    printf("%d  ", root->data);
    inorder(root->right);
}

int main()
{
    Node *root = NULL;
    int n, val;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
    {
        printf("\nInsert value %d: ", i);
        scanf("%d", &val);

        root = insertNode(root, val);
        checkAVL(root);
    }

    printf("\nTotal rotations performed = %d\n", totalRotations);
    inorder(root);
    return 0;
}
