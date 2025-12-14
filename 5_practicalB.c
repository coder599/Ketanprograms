#include <stdio.h>

void heapify(int heap[], int size, int i) {
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < size && heap[left] < heap[smallest]){
        smallest = left;
    }
    if (right < size && heap[right] < heap[smallest]){
         smallest = right;
    }
       

    if (smallest != i) {
        int temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        heapify(heap, size, smallest);
    }
}

void insertHeap(int heap[], int size, int value) {
    heap[size] = value;
    int i = size;
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] > heap[i]) {
            int temp = heap[parent];
            heap[parent] = heap[i];
            heap[i] = temp;
            i = parent;
        } 
        else 
        {
            break;
        }
    }
}

int extractMin(int heap[], int size) {
    int root = heap[0];
    heap[0] = heap[size - 1];
    heapify(heap, size - 1, 0);
    
    return root;
}

void topK(int arr[], int n, int k) {
    int heap[100];
    int heapSize = 0;

    for (int i = 0; i < n; i++) {
        if (heapSize < k) {
            insertHeap(heap, heapSize, arr[i]);
            heapSize++;
        } else if (arr[i] > heap[0]) {
            heap[0] = arr[i];
            heapify(heap, heapSize, 0);
        }
    }

    int result[100];
    for (int i = k - 1; i >= 0; i--) {
        result[i] = heap[0];
        heap[0] = heap[heapSize - 1];
        heapSize--;
        heapify(heap, heapSize, 0);
    }

    for (int i = 0; i < k; i++)
        printf("%d ", result[i]);
    printf("\n");
}

void main() {
    int arr[] = {3, 2, 1, 5, 6, 4};
    
    printf("Array : ");
    for (int i = 0; i < 6; i++)
    {
        printf("%d \n",arr[i]);
    }
    
    printf("Top 2 Element : ");
    topK(arr, 6, 2);
}
