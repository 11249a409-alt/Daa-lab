
## **AIM**

To implement **Randomized Quick Sort** using the **divide and conquer technique** by selecting a **random pivot** to improve average performance and avoid worst-case behavior.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of elements `n`.
3. Read the array elements.
4. Apply Quick Sort:

   * Choose a **random pivot** from the array.
   * Swap it with the last element.
   * Partition the array:

     * Elements smaller than pivot → left
     * Elements greater than pivot → right
5. Recursively apply Quick Sort to left and right subarrays.
6. Display the sorted array.
7. Stop the program.

---

## **SOURCE CODE**

```c id="q9x5rt"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Swap function
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Partition function
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;

    for(j = low; j < high; j++)
    {
        if(arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

// Randomized partition
int randomPartition(int arr[], int low, int high)
{
    int random = low + rand() % (high - low + 1);
    swap(&arr[random], &arr[high]);
    return partition(arr, low, high);
}

// Quick Sort function
void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
        int pi = randomPartition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[50], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Seed random number generator
    srand(time(0));

    quickSort(arr, 0, n - 1);

    printf("Sorted array:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
```

---

## ** OUTPUT**

```id="x7m2kp"
Enter number of elements: 5
Enter elements:
5 2 9 1 6
Sorted array:
1 2 5 6 9
```

---

## **RESULT**

The program successfully implements **Randomized Quick Sort** using the **divide and conquer approach**.

* Random pivot selection helps avoid worst-case scenarios
* Average time complexity is **O(n log n)**
* Worst-case complexity is **O(n²)** but occurs rarely

