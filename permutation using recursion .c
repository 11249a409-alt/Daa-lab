## **AIM**

To write a C program to generate and display all possible **permutations** of a given set of elements using **recursion**.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of elements `n`.
3. Read the elements into an array.
4. Define a recursive function to generate permutations:

   * Fix one element at a time.
   * Swap the current element with the next elements.
   * Call the function recursively for the remaining elements.
   * Backtrack (swap back to original position).
5. When the starting index equals the last index, print the permutation.
6. Stop the program.

---

## **SOURCE CODE**

```c id="9i3s3u"
#include <stdio.h>

// Function to swap two elements
void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive function to generate permutations
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
            swap(&arr[start], &arr[i]);   // Swap
            permute(arr, start + 1, end); // Recursive call
            swap(&arr[start], &arr[i]);   // Backtrack
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
```

---

## **SAMPLE OUTPUT**

```id="c0t9q6"
Enter number of elements: 3
Enter elements:
1 2 3
All possible permutations are:
1 2 3
1 3 2
2 1 3
2 3 1
3 2 1
3 1 2
```

---

## **RESULT**

The program successfully generates all possible **permutations** of the given set of elements using recursion.

* The total number of permutations generated is **n!**
* The program uses **backtracking** technique with recursion

