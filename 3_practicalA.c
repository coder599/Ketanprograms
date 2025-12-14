#include <stdio.h>

// Function for bubble sort
void bubblesort(int *arr, int n)
{
    // Comparing the numbers with even indices only
    for (int i = 0; i < n; i += 2)
    {
        for (int j = 0; j < n - i - 2; j += 2)
        {
            if (arr[j] > arr[j + 2])
            {
                int temp = arr[j];
                arr[j] = arr[j + 2];
                arr[j + 2] = temp;
            }
        }
    }
}

// Function to print array
void display(int *arr)
{

    for (int i = 0; i < 6; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void main()
{
    int arr[6] = {4, 3, 2, 1, 6, 5};

    printf("Before Sorting :\n");
    display(arr);
    bubblesort(arr, 6);
    printf("after Sorting :\n");
    display(arr);
}