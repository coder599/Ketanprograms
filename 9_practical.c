#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1, size = 0;

void enqueue(int value) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    if (front == -1) {
        front = 0;
    }
    rear = (rear + 1) % MAX;  
    queue[rear] = value;
    size++;
}

void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }
    int i = front;
    for (int count = 0; count < size; count++) {
        printf("%d ", queue[i]);
        i = (i + 1) % MAX;  
    }
    printf("\n");
}

void rotateRight(int k) {
    if (size == 0 || k <= 0 || k>size){
         return;
    }

    int temp[MAX];

    //Copy to temp
    for (int i = 0; i < size; i++) {
        int newPos = (i + k) % size;  
        temp[newPos] = queue[(front + i) % MAX];
    }

    // Copy back to queue
    for (int i = 0; i < size; i++) {
        queue[(front + i) % MAX] = temp[i];
    }
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);

    int k = 2;

    printf("Original Circular Queue: ");
    display();

    rotateRight(k);

    printf("After rotating right by %d: ", k);
    display();

    return 0;
}
