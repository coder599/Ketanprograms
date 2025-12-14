#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;

void enqueue(int value) {
    if (rear == MAX - 1) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1)
        front = 0;
    queue[++rear] = value;
}

int dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

void reverseFirstK(int k) {
    if (front == -1 || k <= 0 || k > (rear - front + 1)){
        return;
    }
        

    int stack[MAX];
    int top = -1;

    // Push first k elements into stack
    for (int i = 0; i < k; i++)
        stack[++top] = dequeue();

    // Pop and enqueue back
    while (top != -1)
        enqueue(stack[top--]);

    //Move remaining elements to back
    int remaining = (rear - front + 1) - k;
    for (int i = 0; i < remaining; i++){
        int ele = dequeue();
         enqueue(ele);
    }
       
}

int main() {
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    enqueue(5);

    int k = 3;

    printf("Original Queue: ");
    display();

    reverseFirstK(k);

    printf("After reversing first %d elements: ", k);
    display();

    return 0;
}
