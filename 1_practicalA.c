#include <stdio.h>

int minsubarray(int *arr, int n, int k)
{
    int minlen=n+1;
    int sum = 0, j = 0;
    int start,end;

    //Sum all the elements from index 0 to index untill the sum > key 
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        while (sum > k)
        {
            //When the sum > key get its length
            int currlen = i - j + 1;

            //Find minimum length by comparing with current length
            if (currlen < minlen)
            {
                minlen = currlen;
                //Initialize start and end to traverse subarray
                start = j;
                end = i;
            }
            //Subtract element from index 0 to index untill sum > key
            sum -= arr[j];
            j++;
        }
    }

    //Print the subarray
    printf("Subarray: ");
    for (int i = start; i <= end; i++)
    {
        printf("%d ", arr[i]);
    }

    return minlen;
}

void main()
{
    int arr[5];
    printf("Enter Array of 5 : ");
    for (int i = 0; i < 5; i++)
    {
        scanf("%d", &arr[i]);
    }

    int k;
    printf("Enter Key ");
    scanf("%d", &k);

    int minlen=minsubarray(arr, 5, k);
    //print minimum length
    printf("\n%d is the Minimum length",minlen);

}