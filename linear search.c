## **AIM**

To write a C program to perform **linear search** on an array of 10,000 random numbers and to **measure the time taken** to search for a given key.

---

## **ALGORITHM**

1. Start the program.
2. Declare an array of size 10,000.
3. Generate 10,000 random numbers using `rand()` and store them in the array.
4. Read the key element to be searched from the user.
5. Start the timer using `clock()`.
6. Traverse the array from index 0 to 9999:

   * If the current element equals the key, record its position and stop.
7. Stop the timer using `clock()`.
8. Calculate time taken:
   [
   \text{Time} = \frac{(end - start)}{CLOCKS_PER_SEC}
   ]
9. Display whether the element is found or not.
10. Print the time taken for the search.
11. Stop the program.

---

## **SOURCE CODE**

```c
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

    // Generate random numbers
    for(i = 0; i < SIZE; i++)
    {
        arr[i] = rand() % 100000; // random numbers between 0 and 99999
    }

    // Input key
    printf("Enter the element to search: ");
    scanf("%d", &key);

    // Start time
    start = clock();

    // Linear Search
    for(i = 0; i < SIZE; i++)
    {
        if(arr[i] == key)
        {
            found = 1;
            break;
        }
    }

    // End time
    end = clock();

    // Calculate time
    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    // Output result
    if(found)
        printf("Element found at position: %d\n", i + 1);
    else
        printf("Element not found\n");

    printf("Time taken for search: %f seconds\n", time_taken);

    return 0;
}
```

---

## ** OUTPUT**

```
Enter the element to search: 54321
Element not found
Time taken for search: 0.000012 seconds
```

(OR)

```
Enter the element to search: 12345
Element found at position: 6789
Time taken for search: 0.000008 seconds
```

---

## **RESULT**

The program successfully performs **linear search** on an array of 10,000 random numbers.
The time taken to search for a key element is measured using the `clock()` function.

