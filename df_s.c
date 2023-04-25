#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int visited[MAX_SIZE];
int adj[MAX_SIZE][MAX_SIZE];

void dfs(int vertex, int n)
{
    visited[vertex] = 1;
    printf("%d ", vertex);

    for (int i = 0; i < n; i++)
    {

        if (adj[vertex][i] == 1 && visited[i] == 0)
        {
            dfs(i, n);
        }
    }
}

int main()
{
    int n, start;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix: ");
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    printf("DFS traversal: ");
    dfs(start, n);

    return 0;
}
