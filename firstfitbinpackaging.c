## **AIM**

To write a C program to implement the **First Fit Bin Packing algorithm** and display the **remaining space in each bin** after packing all items.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of items `n`.
3. Read the sizes of the items.
4. Read the bin capacity.
5. Initialize all bins with full capacity.
6. For each item:

   * Traverse the bins from first to last.
   * Place the item in the **first bin** where it fits.
   * Reduce the remaining capacity of that bin.
7. After placing all items, display:

   * Bin number
   * Remaining space in each bin
8. Stop the program.

---

## **SOURCE CODE**

```c id="9q7x2m"
#include <stdio.h>

int main()
{
    int n, i, j;
    int items[50];
    int bin_capacity;
    int bin_rem[50]; // remaining capacity in bins

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter sizes of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i]);
    }

    printf("Enter bin capacity: ");
    scanf("%d", &bin_capacity);

    // Initialize bins
    for(i = 0; i < n; i++)
    {
        bin_rem[i] = bin_capacity;
    }

    // First Fit Algorithm
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            if(bin_rem[j] >= items[i])
            {
                bin_rem[j] -= items[i];
                break;
            }
        }
    }

    // Display remaining space
    printf("\nRemaining space in bins:\n");
    for(i = 0; i < n; i++)
    {
        if(bin_rem[i] != bin_capacity) // only used bins
        {
            printf("Bin %d: %d\n", i + 1, bin_rem[i]);
        }
    }

    return 0;
}
```

---

## ** OUTPUT**

```id="8dlvlt"
Enter number of items: 5
Enter sizes of items:
4 8 1 4 2
Enter bin capacity: 10

Remaining space in bins:
Bin 1: 2
Bin 2: 2
Bin 3: 9
```

---

## **RESULT**

The program successfully implements the **First Fit Bin Packing algorithm**.

* Each item is placed in the **first available bin** where it fits.
* Remaining space in each bin is displayed after packing.

---

