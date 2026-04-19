#include <stdio.h>

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end)
{
    int i;

    if(start == end)
    {
        for(i = 0; i <= end; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
    else
    {
        for(i = start; i <= end; i++)
        {
            swap(&arr[start], &arr[i]);
            permute(arr, start + 1, end);
            swap(&arr[start], &arr[i]);
        }
    }
}

int main()
{
    int arr[10], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("All possible permutations are:\n");
    permute(arr, 0, n - 1);

    return 0;
}
