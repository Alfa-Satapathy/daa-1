#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int visited[MAX_SIZE];       
int adj[MAX_SIZE][MAX_SIZE]; 
int queue[MAX_SIZE];         
int front = -1, rear = -1;   

void enqueue(int vertex)
{
    if (rear == MAX_SIZE - 1)
    {
        printf("Queue overflow!\n");
        exit(1);
    }
    if (front == -1)
    {
        front = 0;
    }
    rear++;
    queue[rear] = vertex;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("Queue underflow!\n");
        exit(1);
    }
    int dequeued = queue[front];
    front++;
    return dequeued;
}

void bfs(int start, int n)
{
    visited[start] = 1; 
    enqueue(start);     

    while (front != -1 && front <= rear)
    {
        int current = dequeue(); 
        printf("%d ", current);  

        for (int i = 0; i < n; i++)
        {
            
            if (adj[current][i] == 1 && visited[i] == 0)
            {
                visited[i] = 1; 
                enqueue(i);    
            }
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

    printf("BFS traversal: ");
    bfs(start, n);

    return 0;
}