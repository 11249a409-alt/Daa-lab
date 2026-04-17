## **AIM**

To write a C program to find the **Vertex Cover** of a given **undirected graph** using an **approximation algorithm** based on its adjacency matrix.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of vertices `n`.
3. Read the adjacency matrix of the graph.
4. Initialize all vertices as **not included** in the vertex cover.
5. Repeat for all edges:

   * If an edge `(u, v)` is not covered:

     * Include both `u` and `v` in the vertex cover
     * Mark all edges connected to `u` and `v` as covered
6. Continue until all edges are covered.
7. Display the vertices in the vertex cover.
8. Stop the program.

---

## **SOURCE CODE**

```c id="v8k3zt"
#include <stdio.h>

#define MAX 10

int main()
{
    int n, i, j;
    int graph[MAX][MAX];
    int visited[MAX] = {0};

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("\nApproximate Vertex Cover:\n");

    // Approximation Algorithm
    for(i = 0; i < n; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(graph[i][j] == 1)
            {
                if(!visited[i] && !visited[j])
                {
                    visited[i] = 1;
                    visited[j] = 1;
                    printf("%d %d ", i, j);
                }
            }
        }
    }

    printf("\n");

    return 0;
}
```

---

## * OUTPUT**

```id="p6x2vn"
Enter number of vertices: 4
Enter adjacency matrix:
0 1 1 0
1 0 1 1
1 1 0 1
0 1 1 0

Approximate Vertex Cover:
0 1 2 3
```

---

## **RESULT**

The program successfully finds an **approximate vertex cover** for the given undirected graph.

* Uses a **greedy 2-approximation algorithm**
* The solution may not be optimal but is efficient
* Time complexity is **O(n²)** using adjacency matrix

---


