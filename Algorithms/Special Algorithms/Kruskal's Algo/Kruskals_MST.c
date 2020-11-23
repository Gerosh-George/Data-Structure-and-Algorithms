#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char node[6] = {'A', 'B', 'C', 'D', 'E', 'F'};

struct Edge
{
    int src;
    int dest;
    int weight;
};

struct Graph
{
    int V;
    int E;
    struct Edge *edge;
};

struct Graph *createGraph(int V, int E)
{
    struct Graph *graph = (struct Graph *)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge *)malloc(E * sizeof(struct Edge));

    return graph;
}

void sort(struct Graph *graph)
{
    for (int i = 0; i < graph->E; i++)
    {
        for (int j = 0; j < graph->E - i - 1; j++)
        {
            if (graph->edge[j].weight > graph->edge[j + 1].weight)
            {
                struct Edge temp = graph->edge[j];
                graph->edge[j] = graph->edge[j + 1];
                graph->edge[j + 1] = temp;
            }
        }
    }
}

struct subset
{
    int parent;
    int rank;
};

int find(struct subset subsets[], int i)
{
    if (subsets[i].parent != i)
        subsets[i].parent = find(subsets, subsets[i].parent);

    return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
    int xvalue = find(subsets, x);
    int yvalue = find(subsets, y);

    if (subsets[xvalue].rank < subsets[yvalue].rank)
    {
        subsets[xvalue].parent = yvalue;
    }
    else if (subsets[xvalue].rank > subsets[yvalue].rank)
    {
        subsets[yvalue].parent = xvalue;
    }
    else
    {
        subsets[yvalue].parent = xvalue;
        subsets[xvalue].rank++;
    }
}

void kruskalMST(struct Graph *graph)
{
    int V = graph->V;
    struct Edge result[V]; // Tnis will store the resultant MST
    int e = 0;             // An index variable, used for result[]
    int i = 0;             // An index variable, used for sorted edges

    sort(graph); // sorting the edges in ascending order

    struct subset *subsets = (struct subset *)malloc(V * sizeof(struct subset));

    for (int v = 0; v < V; v++)
    {
        subsets[v].parent = v;
        subsets[v].rank = 0;
    }

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E)
    {
        // Step 2: Pick the smallest edge. And increment
        // the index for next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(subsets, next_edge.src);
        int y = find(subsets, next_edge.dest);

        // If including this edge does't cause cycle,
        // include it in result and increment the index
        // of result for next edge
        if (x != y)
        {
            result[e++] = next_edge;
            Union(subsets, x, y);
        }
        // Else discard the next_edge
    }

    int sum = 0;
    for (i = 0; i < e; ++i)
    {
        printf("%c -- %c == %d\n", node[result[i].src], node[result[i].dest], result[i].weight);
        sum += result[i].weight;
    }
    printf("Minimum Spanning Tree Cost: %d", sum);
    return;
}

int main()
{
    int V = 6;
    int E = 9;

    struct Graph *graph = createGraph(V, E);

    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 73;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 18;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 22;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 4;
    graph->edge[3].weight = 21;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 3;
    graph->edge[4].weight = 11;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 44;

    graph->edge[6].src = 2;
    graph->edge[6].dest = 5;
    graph->edge[6].weight = 44;

    graph->edge[7].src = 3;
    graph->edge[7].dest = 5;
    graph->edge[7].weight = 32;

    graph->edge[8].src = 4;
    graph->edge[8].dest = 5;
    graph->edge[8].weight = 45;

    kruskalMST(graph);
}
