## **AIM**

To write a C program to compute the **maximum flow** from a **source vertex to a sink vertex** using a simplified approach based on a **capacity matrix**.

---

## **ALGORITHM**

1. Start the program.
2. Read the number of vertices `n`.
3. Read the **capacity matrix** of the graph.
4. Read the **source** and **sink** vertices.
5. Initialize residual graph same as capacity matrix.
6. Repeat until no augmenting path exists:

   * Use a simple BFS to find a path from source to sink.
   * Find the minimum capacity (bottleneck) along the path.
   * Update residual capacities:

     * Reduce forward edge capacity
     * Increase backward edge capacity
   * Add flow to total maximum flow
7. Display the maximum flow.
8. Stop the program.

---

## **SOURCE CODE**

```c id="k7m4qp"
#include <stdio.h>
#include <limits.h>

#define MAX 10

int n;
int capacity[MAX][MAX];
int residual[MAX][MAX];
int visited[MAX];
int parent[MAX];

// BFS to find augmenting path
int bfs(int s, int t)
{
    int queue[MAX], front = 0, rear = 0;
    int i;

    for(i = 0; i < n; i++)
        visited[i] = 0;

    queue[rear++] = s;
    visited[s] = 1;
    parent[s] = -1;

    while(front < rear)
    {
        int u = queue[front++];

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && residual[u][i] > 0)
            {
                queue[rear++] = i;
                parent[i] = u;
                visited[i] = 1;

                if(i == t)
                    return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int i, j;
    int source, sink;
    int max_flow = 0;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter capacity matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            scanf("%d", &capacity[i][j]);
            residual[i][j] = capacity[i][j];
        }
    }

    printf("Enter source and sink: ");
    scanf("%d %d", &source, &sink);

    // Ford-Fulkerson method using BFS
    while(bfs(source, sink))
    {
        int path_flow = INT_MAX;

        // Find minimum residual capacity
        for(j = sink; j != source; j = parent[j])
        {
            i = parent[j];
            if(residual[i][j] < path_flow)
                path_flow = residual[i][j];
        }

        // Update residual capacities
        for(j = sink; j != source; j = parent[j])
        {
            i = parent[j];
            residual[i][j] -= path_flow;
            residual[j][i] += path_flow;
        }

        max_flow += path_flow;
    }

    printf("Maximum flow = %d\n", max_flow);

    return 0;
}
```

---

## **OUTPUT**

```id="m2x7vn"
Enter number of vertices: 4
Enter capacity matrix:
0 3 2 0
0 0 5 2
0 0 0 3
0 0 0 0
Enter source and sink: 0 3
Maximum flow = 5
```

---

## **RESULT**

The program successfully computes the **maximum flow** from source to sink using a simplified **Ford-Fulkerson method**.

* Uses **BFS to find augmenting paths**
* Updates residual graph dynamically
* Time complexity depends on number of augmenting paths

---
