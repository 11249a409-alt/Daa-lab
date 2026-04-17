## **AIM**

To write a C program to solve the **Travelling Salesman Problem (TSP)** using **recursion** and find the **minimum tour cost** for visiting all cities exactly once and returning to the starting city.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of cities `n`.
3. Read the cost adjacency matrix.
4. Create a visited array to track visited cities.
5. Start from city 0 (starting city).
6. Use a recursive function:

   * Mark current city as visited.
   * For each unvisited city:

     * Calculate cost of visiting that city + recursive call.
   * Return the minimum cost path.
7. Add the cost to return to the starting city.
8. Print the minimum tour cost.
9. Stop the program.

---

## **SOURCE CODE**

```c id="t6x8pn"
#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int cost[MAX][MAX];
int visited[MAX];

// Recursive function for TSP
int tsp(int current, int count)
{
    int i;
    int min_cost = INT_MAX;
    int temp_cost;

    // If all cities visited, return cost to go back to start
    if(count == n && cost[current][0])
    {
        return cost[current][0];
    }

    for(i = 0; i < n; i++)
    {
        if(!visited[i] && cost[current][i])
        {
            visited[i] = 1;

            temp_cost = cost[current][i] + tsp(i, count + 1);

            if(temp_cost < min_cost)
                min_cost = temp_cost;

            visited[i] = 0; // backtrack
        }
    }

    return min_cost;
}

int main()
{
    int i, j;
    int result;

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter cost matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
        }
    }

    // Initialize visited array
    for(i = 0; i < n; i++)
        visited[i] = 0;

    visited[0] = 1; // start from city 0

    result = tsp(0, 1);

    printf("Minimum travelling cost = %d\n", result);

    return 0;
}
```

---

## ** OUTPUT**

```id="t6m9rs"
Enter number of cities: 4
Enter cost matrix:
0 10 15 20
10 0 35 25
15 35 0 30
20 25 30 0
Minimum travelling cost = 80
```

---

## **RESULT**

The program successfully solves the **Travelling Salesman Problem** using recursion.

* It explores all possible paths (brute force).
* Finds the **minimum cost** of visiting all cities exactly once and returning to the starting city.
* Time complexity is **O(n!)**, which is very high for large inputs.

