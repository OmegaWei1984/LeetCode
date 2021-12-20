#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    // int arr[] = {11,11,9,4,3,3,3,1,-1,-1,3,3,3,5,5,5};
    int arr[] = {6, 5, 4 ,4};
    // int arr[] = {1, 2, 2, 3};
    int *A = arr;
    int ASize = sizeof(arr) / sizeof(arr[0]);

    bool isDec;
    int count = 0;
    for (int i = 0; i < ASize - 1; i++)
    {
        count++;
        if (A[i + 1] - A[i] != 0)
        {
            isDec = (A[i + 1] - A[i] < 0);
            break;
        }
    }
    if (count == ASize - 1)
    { 
        printf("true");
        return 0;
    }
    for (int i = count; i < ASize - 1; i++)
    {
        if ((isDec && (A[i + 1] - A[i] > 0)) || (!isDec && (A[i + 1] - A[i] < 0)))
        {
            printf("false");
            return 0;
        }
    }
    printf("is true");

    return 0;
}