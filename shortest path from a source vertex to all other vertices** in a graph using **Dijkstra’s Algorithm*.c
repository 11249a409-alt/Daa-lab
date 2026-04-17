
## **AIM**

To write a C program to find the **shortest path from a source vertex to all other vertices** in a graph using **Dijkstra’s Algorithm**.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of vertices `n`.
3. Read the adjacency matrix of the graph.
4. Read the source vertex.
5. Initialize:

   * `dist[]` array with infinity
   * `visited[]` array as 0
   * Set distance of source = 0
6. Repeat for all vertices:

   * Select the unvisited vertex with minimum distance
   * Mark it as visited
   * Update distances of its adjacent vertices
7. Display the shortest distances from source to all vertices.
8. Stop the program.

---

## **SOURCE CODE**

```c id="d8k3xm"
#include <stdio.h>
#include <limits.h>

#define MAX 10

int main()
{
    int n, i, j, src;
    int cost[MAX][MAX];
    int dist[MAX];
    int visited[MAX];
    int min, u;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &cost[i][j]);
            if(cost[i][j] == 0 && i != j)
                cost[i][j] = INT_MAX; // no edge
        }
    }

    printf("Enter source vertex (0 to %d): ", n - 1);
    scanf("%d", &src);

    // Initialize arrays
    for(i = 0; i < n; i++)
    {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src] = 0;

    // Dijkstra's Algorithm
    for(i = 0; i < n - 1; i++)
    {
        min = INT_MAX;

        // Find minimum distance vertex
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && dist[j] <= min)
            {
                min = dist[j];
                u = j;
            }
        }

        visited[u] = 1;

        // Update distances
        for(j = 0; j < n; j++)
        {
            if(!visited[j] && cost[u][j] != INT_MAX &&
               dist[u] != INT_MAX &&
               dist[u] + cost[u][j] < dist[j])
            {
                dist[j] = dist[u] + cost[u][j];
            }
        }
    }

    // Display results
    printf("\nShortest distances from source %d:\n", src);
    for(i = 0; i < n; i++)
    {
        printf("To vertex %d = %d\n", i, dist[i]);
    }

    return 0;
}
```

---

## ** OUTPUT**

```id="6nq8yb"
Enter number of vertices: 4
Enter adjacency matrix:
0 10 0 30
10 0 50 0
0 50 0 20
30 0 20 0
Enter source vertex (0 to 3): 0

Shortest distances from source 0:
To vertex 0 = 0
To vertex 1 = 10
To vertex 2 = 50
To vertex 3 = 30
```

---

## **RESULT**

The program successfully finds the **shortest path** from the given source vertex to all other vertices using **Dijkstra’s Algorithm**.

* Works only for graphs with **non-negative weights**
* Time complexity is **O(n²)** using adjacency matrix

---
