#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

#define V 6

char node[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

int minKey(int key[], bool mstSet[])
{

    int min = INT_MAX;
    int min_index;

    for (int v = 0; v < V; v++)
    {
        if (mstSet[v] == false && key[v] < min)
        {
            min = key[v];
            min_index = v;
        }
    }

    return min_index;
}

int printMST(int parent[], int graph[V][V])
{

    int sum = 0;
    printf("Edge \tWeight\n");
    for (int i = 0; i < V; i++)
    {
        if (parent[i] != -1)
        {
            printf("%c - %c \t%d \n", node[parent[i]], node[i], graph[i][parent[i]]);
            sum += graph[i][parent[i]];
        }
    }

    printf("Minimum spanning tree cost: %d", sum);
}

void primMST(int graph[V][V])
{

    int parent[V]; //Array to store the MST

    int key[V]; //Array to used to pick minimum weight edge

    bool mstSet[V]; //To represent set of vertices included MST

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[1] = 0;
    parent[1] = -1;

    for (int i = 0; i < V - 1; i++)
    {

        int u = minKey(key, mstSet);

        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {

            if (graph[u][v] != 0 && mstSet[v] == false && graph[u][v] < key[v])
            {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{

    int graph[V][V] = {{0, 73, 0, 18, 0, 0},
                       {73, 0, 22, 0, 21, 0},
                       {0, 22, 0, 11, 44, 44},
                       {18, 0, 11, 0, 0, 32},
                       {0, 21, 44, 0, 0, 45},
                       {0, 0, 44, 32, 45, 0}};

    primMST(graph);
}
