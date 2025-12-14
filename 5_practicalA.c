#include <stdio.h>

int partition(int *arr, int low, int high)
{
    int mid = (low + high) / 2;
    int pivot = arr[mid];
    int p = low;
    int q = high;

    while (p < q)
    {
        while (arr[p] < pivot)
        {
            p++;
        }
        while (arr[q] > pivot)
        {
            q++;
        }
        if (p < q)
        {
            int temp = arr[p];
            arr[p] = arr[q];
            arr[q] = temp;
            p++;
            q--;
        }
    }

    return p;
}

void quick_Sort(int *arr, int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(arr, low, high);
        quick_Sort(arr, pivot_index + 1, high);
        quick_Sort(arr, low, pivot_index - 1);
    }
}

void display(int *arr)
{
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void main()
{

    int arr[5] = {2, 13, 67, 43, 1};

    printf("Before Sorting : \n");
    display(arr);
    quick_Sort(arr, 0, 5 - 1);
    printf("After Sorting : \n");
    display(arr);
}