## **AIM**

To write a C program to analyze the time required to perform **binary search** on a sorted array of 10,000 randomly generated numbers using the `clock()` function.

---

## **ALGORITHM**

1. Start the program.
2. Declare an array of size 10,000.
3. Generate random numbers using `rand()`.
4. Sort the array using **bubble sort**.
5. Read the key element from the user.
6. Start the timer using `clock()`.
7. Perform binary search:

   * Set `low = 0`, `high = SIZE - 1`
   * Find `mid = (low + high) / 2`
   * Compare key with middle element
   * Adjust search range accordingly
8. Stop the timer.
9. Calculate time in **clock ticks**:

   ```
   time = end - start
   ```
10. Display index and time taken.
11. Stop.

---

## **SOURCE CODE**

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

// Bubble Sort Function
void bubbleSort(int arr[])
{
    int i, j, temp;
    for(i = 0; i < SIZE - 1; i++)
    {
        for(j = 0; j < SIZE - i - 1; j++)
        {
            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Binary Search Function
int binarySearch(int arr[], int key)
{
    int low = 0, high = SIZE - 1, mid;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == key)
            return mid;
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    int arr[SIZE];
    int key, index;
    int i;
    clock_t start, end;
    double time_taken;

    // Generate random numbers
    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100000;
    }

    // Sort the array
    bubbleSort(arr);

    // Input key
    printf("Enter key: ");
    scanf("%d", &key);

    // Start time
    start = clock();

    // Binary search
    index = binarySearch(arr, key);

    // End time
    end = clock();

    // Time in clock ticks
    time_taken = (double)(end - start);

    // Output
    if(index != -1)
        printf("key st %d with index at %d,time taken as is %.5f clock ticks\n", key, index);
    else
        printf("key st %d not found,time taken as is %.5f clock ticks\n", key, time_taken);

    return 0;
}
```

---

## **OUTPUT**

```
Enter key: 523
key st 523 with index at 4876,time taken as is 2.00000 clock ticks
```

