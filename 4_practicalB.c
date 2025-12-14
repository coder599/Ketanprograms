#include<stdio.h>
#include<stdlib.h>

int *selectionSort(int *arr,int n){
    int *result = (int*)malloc(n*sizeof(int));
    int temp[n];
    for (int i = 0; i < n; i++)
    {
        temp[i]=i;
    }

    for (int i = 0; i < n; i++)
    {
        int minIndex=i;
        for (int j = i+1; j < n; j++)
        {
            if (arr[minIndex]>arr[j])
            {
                minIndex=j;
            }
            
        }
        //swap the actual array
        int t=arr[i];
        arr[i]=arr[minIndex];
        arr[minIndex]=t;

        //Swap the indices array
        t = temp[minIndex];
        temp[minIndex]=temp[i];
        temp[i]=t;
    }

    //Storing the actual position of elements in sorted array
    for (int i = 0; i < n; i++)
    {
        result[temp[i]] = i;
    }
    
    return result;
    
    
}

void main(){
    int arr[4] = {40,10,20,30};
    int n=4;

    int *indices=selectionSort(arr,n);
    printf("Original indices of array : \n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n",indices[i]);
    }
    
}