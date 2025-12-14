#include<stdio.h>

//to count the inversions
static int inversion=0;

void merge(int *arr,int low,int mid,int high){

    int i=low,j=mid+1,k=0,temp[100];

    while (i<=mid&&j<=high)
    {
        if (arr[i]>arr[j])
        {
            temp[k++]=arr[j++];
            //
            inversion +=mid-i+1;

        }
        else{
            temp[k++]=arr[i++];
        }
        
    }
    while (i<=mid)
    {
        temp[k++]=arr[i++];
    }
    while (j<=high)
    {
        temp[k++]=arr[j++];
    }

    for (int i = 0; i < k; i++)
    {
        arr[i+low]=temp[i];
    }
    
}

void merge_sort(int *arr,int low,int high){
    if(low<high){
        int mid=(low+high)/2;

        merge_sort(arr,low,mid);
        merge_sort(arr,mid+1,high);
        merge(arr,low,mid,high);
    }
}
void display(int *arr){
    for (int i = 0; i < 4; i++)
    {
        printf("%d\n",arr[i]);
    }
    
}


void main(){
    int arr[4]={8,4,2,1};

    printf("Before Sorting :\n");
    display(arr);
    merge_sort(arr,0,3);
    printf("after Sorting :\n");
    display(arr);
    printf("Inversion : %d",inversion);
}