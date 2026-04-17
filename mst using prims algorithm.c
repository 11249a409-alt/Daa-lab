## **AIM**

To write a C program to find the **Minimum Spanning Tree (MST)** of a graph using **Prim’s Algorithm**.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of vertices `n`.
3. Read the adjacency matrix of the graph.
4. Initialize:

   * `selected[]` array to track included vertices
   * Select the first vertex as starting point
5. Repeat until `n-1` edges are selected:

   * Find the minimum weight edge connecting:

     * a selected vertex
     * to an unselected vertex
   * Add this edge to MST
   * Mark the new vertex as selected
6. Display the edges of MST and total cost.
7. Stop the program.

---

## **SOURCE CODE**

```c id="p4z7mn"
#include <stdio.h>
#include <limits.h>

#define MAX 10

int main()
{
    int n, i, j;
    int cost[MAX][MAX];
    int selected[MAX];
    int no_edge = 0;
    int min, x, y;
    int total_cost = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0)
                cost[i][j] = INT_MAX; // no edge
        }
    }

    // Initialize selected array
    for(i = 0; i < n; i++)
        selected[i] = 0;

    selected[0] = 1; // start from vertex 0

    printf("\nEdges in MST:\n");

    while(no_edge < n - 1)
    {
        min = INT_MAX;
        x = 0;
        y = 0;

        for(i = 0; i < n; i++)
        {
            if(selected[i])
            {
                for(j = 0; j < n; j++)
                {
                    if(!selected[j] && cost[i][j])
                    {
                        if(min > cost[i][j])
                        {
                            min = cost[i][j];
                            x = i;
                            y = j;
                        }
                    }
                }
            }
        }

        printf("%d - %d : %d\n", x, y, cost[x][y]);

        total_cost += cost[x][y];
        selected[y] = 1;
        no_edge++;
    }

    printf("Total cost of MST = %d\n", total_cost);

    return 0;
}
```

---

## ** OUTPUT**

```id="y7q2wl"
Enter number of vertices: 4
Enter adjacency matrix:
0 2 0 6
2 0 3 8
0 3 0 0
6 8 0 0

Edges in MST:
0 - 1 : 2
1 - 2 : 3
0 - 3 : 6
Total cost of MST = 11
```

---

## **RESULT**

The program successfully finds the **Minimum Spanning Tree** using **Prim’s Algorithm**.

* It selects edges with minimum weight without forming cycles.
* Total cost of MST is calculated.
* Time complexity is **O(n²)** using adjacency matrix.

---

