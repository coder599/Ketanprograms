#include <stdio.h>

int linear(int *arr, int n, int num, int k) {
    int i;

    // Jump of k
    for (i = 0; i < n; i += k) {
        if (arr[i] == num)
            return i;

        // If current element > k then it lies in previous block
        if (arr[i] > num)
            break;
    }

    //Search the element if lie in previous block 
    for (int j = i; j >= 0 && j >= i-k; j--) {
        if (arr[j] == num)
            return j;
    }

    return -1; 
}


int main() {
    int num, k,arr[6];

    printf("Enter sorted array elements:\n");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter number to find: ");
    scanf("%d", &num);

    printf("Enter step size k: ");
    scanf("%d", &k);

    int index = linear(arr, 6, num, k);

    if (index == -1)
        printf("Element not found\n");
    else
        printf("Element found at index %d\n", index);

    return 0;
}
