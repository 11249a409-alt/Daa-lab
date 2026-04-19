#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

int main()
{
    int arr[SIZE];
    int key, i, found = 0;
    clock_t start, end;
    double time_taken;

    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100000;
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    start = clock();

    for(i = 0; i < SIZE; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if(found)
        printf("Element found at position: %d\n", i + 1);
    else
        printf("Element not found\n");

    printf("Time taken for search: %f seconds\n", time_taken);

    return 0;
}
