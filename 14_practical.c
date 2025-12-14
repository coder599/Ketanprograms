#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int front, rear;
} Queue;

int isEmptyQueue(Queue *q) { return q->front == -1; }

void enqueue(Queue *q, int x) {
    if (q->rear == MAX - 1) return;
    if (q->front == -1) q->front = 0;
    q->data[++q->rear] = x;
}

int dequeue(Queue *q) {
    if (isEmptyQueue(q)) return -1;
    int x = q->data[q->front];
    if (q->front == q->rear) q->front = q->rear = -1;
    else q->front++;
    return x;
}

void printQueue(Queue *q) {
    printf("[ ");
    if (!isEmptyQueue(q))
        for (int i = q->front; i <= q->rear; i++)
            printf("%d ", q->data[i]);
    printf("]");
}

typedef struct {
    int data[MAX];
    int top;
} Stack;

int isEmptyStack(Stack *s) { return s->top == -1; }
void push(Stack *s, int x) { if (s->top < MAX - 1) s->data[++s->top] = x; }
int pop(Stack *s) { if (isEmptyStack(s)) return -1; return s->data[s->top--]; }

void printStack(Stack *s) {
    printf("[ ");
    for (int i = 0; i <= s->top; i++)
        printf("%d ", s->data[i]);
    printf("]");
}

int adj[MAX][MAX];
int size[MAX];

void addEdge(int u, int v) {
    adj[u][size[u]++] = v;
    adj[v][size[v]++] = u;
}

void printVisited(int visited[], int n) {
    printf("{ ");
    for (int i = 0; i < n; i++)
        if (visited[i]) printf("%d ", i);
    printf("}");
}

void BFS(int start, int n) {
    int visited[MAX] = {0};
    Queue q = {{0}, -1, -1};
    visited[start] = 1;
    enqueue(&q, start);
    int step = 0;

    printf("\n===== BFS Traversal =====\n");
    printf("Init -> Enqueue %d | visited=", start);
    printVisited(visited, n);
    printf(" | queue=");
    printQueue(&q);
    printf("\n");

    while (!isEmptyQueue(&q)) {
        int u = dequeue(&q);
        printf("Step %d: Dequeue %d | visited=", step++, u);
        printVisited(visited, n);
        printf(" | queue=");
        printQueue(&q);
        printf("\n");

        for (int i = 0; i < size[u]; i++) {
            int v = adj[u][i];
            if (!visited[v]) {
                visited[v] = 1;
                enqueue(&q, v);
                printf("  - Enqueue %d | visited=", v);
                printVisited(visited, n);
                printf(" | queue=");
                printQueue(&q);
                printf("\n");
            }
        }
    }
}

void DFS(int start, int n) {
    int visited[MAX] = {0};
    Stack s = {{0}, -1};
    push(&s, start);
    int step = 0;

    printf("\n===== DFS (Iterative) Traversal =====\n");
    printf("Init -> Push %d | visited=", start);
    printVisited(visited, n);
    printf(" | stack=");
    printStack(&s);
    printf("\n");

    while (!isEmptyStack(&s)) {
        int u = pop(&s);
        printf("Step %d: Pop %d | visited=", step++, u);
        printVisited(visited, n);
        printf(" | stack=");
        printStack(&s);
        printf("\n");

        if (!visited[u]) {
            visited[u] = 1;
            printf("  - Visit %d | visited=", u);
            printVisited(visited, n);
            printf("\n");

            for (int i = size[u] - 1; i >= 0; i--) {
                int v = adj[u][i];
                if (!visited[v]) {
                    push(&s, v);
                    printf("     - Push %d | stack=", v);
                    printStack(&s);
                    printf("\n");
                }
            }
        }
    }
}

int main() {
    int n = 7;
    for (int i = 0; i < n; i++) size[i] = 0;

    addEdge(0,1);
    addEdge(0,2);
    addEdge(1,3);
    addEdge(1,4);
    addEdge(2,5);
    addEdge(2,6);
    addEdge(3,5);

    BFS(0, n);
    DFS(0, n);

    return 0;
}
