#include <stdio.h>

//Function for insertion sort
int insertion(int *arr, int n)
{
    //shifts is used to count the number of shifts
    int shifts = 0;
    for (int i = 1; i < n; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            shifts++;
            j--;
        }
        arr[j + 1] = key;
    }
    return shifts;
}

//Function to display array
void display(int *arr)
{

    for (int i = 0; i < 8; i++)
    {
        printf("%d\n", arr[i]);
    }
}

void main()
{
    int arr[8] = {2, 4, 3, 1, 6, 5, 8, 7};

    printf("Before Sorting : \n");
    display(arr);
    int shifts = insertion(arr, 8);
    printf("After Sorting : \n");
    display(arr);
    printf("Total shifts : %d", shifts);
}