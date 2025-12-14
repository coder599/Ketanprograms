#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *front = NULL;
struct Node *rear = NULL;

int isEmpty()
{
    return front == NULL;
}

void enqueue(int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Queue Underflow\n");
        return -1;
    }

    struct Node *temp = front;
    int val = temp->data;
    front = front->next;

    if (front == NULL)
        rear = NULL;

    free(temp);
    return val;
}

void display()
{
    struct Node *temp = front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void rotateQueue(int k)
{
    int len = 0;
    struct Node *temp = front;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }

    if (isEmpty() || k <= 0 || k > len)
    {
        return;
    }

    // Move to kth node
    struct Node *current = front;
    for (int i = 1; i < k; i++)
    {
        current = current->next;
    }

    // Assign front and rear
    temp = current->next;
    current->next = NULL;
    rear->next = front;
    front = temp;
    rear = current;
}

int main()
{
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    int k = 2;

    printf("Original Queue: ");
    display();

    rotateQueue(k);

    printf("After rotating by %d: ", k);
    display();

    return 0;
}
