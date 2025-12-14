#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int vertex;
    struct Node* next;
} Node;

Node* createNode(int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

int main() {
    int vertices, edges;
    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    int adjMatrix[50][50] = {0};  

    Node* adjList[50];
    for (int i = 0; i < vertices; i++)
        adjList[i] = NULL;

    printf("\nEnter edges (u v): \n");
    for (int i = 0; i < edges; i++) {
        int u, v;
        scanf("%d %d", &u, &v);

        // For matrix
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;

        // For list
        Node* newNode1 = createNode(v);
        newNode1->next = adjList[u];
        adjList[u] = newNode1;

        Node* newNode2 = createNode(u);
        newNode2->next = adjList[v];
        adjList[v] = newNode2;
    }

    printf("\nAdjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; i++) {
        printf("%d -> ", i);
        Node* temp = adjList[i];
        while (temp != NULL) {
            printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }

    return 0;
}
