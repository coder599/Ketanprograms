#include <stdio.h>

void bitonic(int arr[], int n) {
    int inc[n], dec[n];

    // Build increasing sequence lengths from left
    inc[0] = 1;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i - 1])
            inc[i] = inc[i - 1] + 1;
        else
            inc[i] = 1;
    }

    // Build decreasing sequence lengths from right
    dec[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        if (arr[i] > arr[i + 1])
            dec[i] = dec[i + 1] + 1;
        else
            dec[i] = 1;
    }

    // Find maximum bitonic subarray length
    int maxlen = 0, start = 0, end = 0;
    for (int i = 0; i < n; i++) {
        int len = inc[i] + dec[i] - 1;
        if (len > maxlen) {
            maxlen = len;
            start = i - inc[i] + 1;
            end = i + dec[i] - 1;
        }
    }

    printf("The length of longest bitonic subarray: %d\n", maxlen);
    printf("Subarray: ");
    for (int i = start; i <= end; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[6];
    printf("Enter Array of 6: ");
    for (int i = 0; i < 6; i++) {
        scanf("%d", &arr[i]);
    }

    bitonic(arr, 6);

    return 0;
}
