#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
    
#define V 6

int cities[V] = {'A', 'B', 'C', 'D', 'E', 'F'};

//pulls out the next city to visit which has smallest distance from source city.
int min_dist(bool visited[], int short_dist[])
{
    int min = INT_MAX;
    int city = -1;
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false && short_dist[i] < min)
        {
            min = short_dist[i];
            city = i;
        }
    }

    return city;
}

bool is_all_city_visited(bool visited[])
{
    for (int i = 0; i < V; i++)
    {
        if (visited[i] == false)
            return false;
    }

    return true;
}

int number_of_connecting_city(int dest, int parent[])
{
    int i = dest;
    int count = 0;
    while (parent[i] != -1)
    {
        count++;
        i = parent[i];
    }

    count++;
    return count;
}

void print_shortest_path(int dest, int parent[], int short_dist[])
{

    int n = number_of_connecting_city(dest, parent);
    int path[n];
    //printf("%d\n", n);

    int k = n - 1;

    int i = dest;
    path[k] = dest;
    while (parent[i] != -1)
    {
        k--;
        path[k] = parent[i];
        i = parent[i];
    }

    printf("\nShortest Path: ");
    for (int i = 0; i < n; i++)
    {
        printf("%c ", cities[path[i]]);
    }
    printf("\nShortest distance: %d\n\n", short_dist[dest]);
}

void dijkstra(int graph[V][V], int src, int dest)
{
    bool visited[V];
    int short_dist[V];
    int parent[V];

    for (int i = 0; i < V; i++)
    {
        short_dist[i] = INT_MAX;
        visited[i] = false;
    }
    short_dist[src] = 0;
    parent[src] = -1;

    int current_city = -1;

    while (!is_all_city_visited(visited))
    {

        current_city = min_dist(visited, short_dist);

        for (int j = 0; j < V; j++)
        {
            if (graph[current_city][j] != 0)
            {

                int visiting_city_dist = short_dist[current_city] + graph[current_city][j];

                if (visiting_city_dist < short_dist[j])
                {
                    short_dist[j] = visiting_city_dist;
                    parent[j] = current_city;
                }
            }
        }

        visited[current_city] = true;
    }

    printf("Source city: %c", cities[src]);
    printf("\nDestination city: %c", cities[dest]);
    print_shortest_path(dest, parent, short_dist);
}

int main()
{
    //used adjacency matrix to represent the graph
    int graph[V][V] = {{0, 73, 0, 18, 0, 0},
                       {73, 0, 22, 0, 21, 0},
                       {0, 22, 0, 11, 44, 44},
                       {18, 0, 11, 0, 0, 32},
                       {0, 21, 44, 0, 0, 45},
                       {0, 0, 44, 32, 45, 0}};

    dijkstra(graph, 1, 0);
    dijkstra(graph, 1, 2);
    dijkstra(graph, 1, 3);
    dijkstra(graph, 1, 4);
    dijkstra(graph, 1, 5);
}