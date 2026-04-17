## **AIM**

To write a C program to solve the **Fractional Knapsack Problem** using the **Greedy method** and find the **maximum possible profit**.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of items `n`.
3. Read the weights and profits of the items.
4. Calculate **profit/weight ratio** for each item.
5. Sort items in **descending order of ratio**.
6. Initialize total profit = 0.
7. For each item:

   * If the whole item can be added, add it completely.
   * Else take the fractional part of the item.
8. Continue until the knapsack is full.
9. Display the maximum profit.
10. Stop the program.

---

## **SOURCE CODE**

```c id="m4t8kp"
#include <stdio.h>

// Structure for items
struct Item
{
    int weight;
    int profit;
    float ratio;
};

// Function to sort items by profit/weight ratio (descending)
void sort(struct Item items[], int n)
{
    int i, j;
    struct Item temp;

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            if(items[j].ratio < items[j + 1].ratio)
            {
                temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n, i;
    float capacity;
    struct Item items[50];
    float total_profit = 0.0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    printf("Enter weights of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i].weight);
    }

    printf("Enter profits of items:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &items[i].profit);
    }

    // Calculate ratio
    for(i = 0; i < n; i++)
    {
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }

    // Sort items
    sort(items, n);

    printf("Enter knapsack capacity: ");
    scanf("%f", &capacity);

    // Greedy approach
    for(i = 0; i < n; i++)
    {
        if(capacity >= items[i].weight)
        {
            capacity -= items[i].weight;
            total_profit += items[i].profit;
        }
        else
        {
            total_profit += items[i].ratio * capacity;
            break;
        }
    }

    printf("Maximum possible profit = %.2f\n", total_profit);

    return 0;
}
```

---

## **SAMPLE OUTPUT**

```id="0f8a8l"
Enter number of items: 3
Enter weights of items:
10 20 30
Enter profits of items:
60 100 120
Enter knapsack capacity: 50
Maximum possible profit = 240.00
```

---

## **RESULT**

The program successfully solves the **Fractional Knapsack Problem** using the **greedy method**.

* Items are selected based on **maximum profit/weight ratio**
* Fractional parts are allowed to maximize profit
* Time complexity is **O(n²)** due to sorting

---


