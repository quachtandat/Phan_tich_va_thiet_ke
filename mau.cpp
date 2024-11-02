#include <stdio.h>
#include <stdlib.h>

// A struct that represents an undirected graph
struct Graph
{
    int V;    // No. of vertices
    int *adj;    // A dynamic array of adjacency lists
};

// A function to create a new graph with V vertices
struct Graph* createGraph(int V)
{
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->adj = (int*) malloc(V * V * sizeof(int));
    for (int i = 0; i < V * V; i++)
        graph->adj[i] = 0;
    return graph;
}

// A function to destroy a graph
void destroyGraph(struct Graph* graph)
{
    free(graph->adj);
    free(graph);
}

// A function to add an edge to graph
void addEdge(struct Graph* graph, int v, int w)
{
    graph->adj[v * graph->V + w] = 1;
    graph->adj[w * graph->V + v] = 1;  // Note: the graph is undirected
}

struct vertexDegree
{
    int v;
    int degree;
};

// A function to compare two vertexDegree structs by degree
int compareByDegree(const void* x, const void* y)
{
    struct vertexDegree* a = (struct vertexDegree*) x;
    struct vertexDegree* b = (struct vertexDegree*) y;
    return b->degree - a->degree;
}

// A function to assign colors (starting from 0) to all vertices and print
// the assignment of colors
void greedyColoring(struct Graph* graph)
{
    int V = graph->V;
    int result[V];

    // Initialize remaining V-1 vertices as unassigned
    for (int u = 1; u < V; u++)
        result[u] = -1;  // no color is assigned to u

    // A temporary array to store the available colors. True
    // value of available[cr] would mean that the color cr is
    // assigned to one of its adjacent vertices
    int available[V];

    for (int cr = 0; cr < V; cr++)
        available[cr] = 0;

    struct vertexDegree arr[V];
    for (int i = 0; i < V; i++)
    {
        arr[i].v = i;
        arr[i].degree = 0;
        for (int j = 0; j < V; j++)
        {
            if (graph->adj[i * V + j] == 1)
                arr[i].degree++;
        }
    }

    qsort(arr, V, sizeof(struct vertexDegree), compareByDegree);

    printf("Sorted vertices \n");
    for (int i = 0; i < V; i++)
    {
        printf("%d ", arr[i].v);
    }
    printf("\n");

    // Assign the first color to first vertex in sorted array
    result[arr[0].v]  = 0;

    // Assign colors to remaining V-1 vertices
    for (int x = 1; x < V; x++)
    {
        int u = arr[x].v;

        // Process all adjacent vertices and flag their colors
        // as unavailable
        for (int i = 0; i < V; i++)
        {
            if (graph->adj[u * V + i] == 1 && result[i] != -1)
                available[result[i]] = 1;
        }

        // Find the first available color
        int cr;
        for (cr = 0; cr < V; cr++)
            if (available[cr] == 0)
                break;

        result[u] = cr; // Assign the found color

        // Reset the values back to false for the next iteration
        for (int i = 0; i < V; i++)
        {
            if (graph->adj[u * V + i] == 1 && result[i] != -1)
                available[result[i]] = 0;
        }
    }

    // print the result
    for (int u = 0; u < V; u++)
        printf("Vertex %d --->  Color %d\n", u, result[u]);
}

// Driver program to test above function
int main()
{
    struct Graph* g1 = createGraph(5);
    addEdge(g1, 0, 1);
    addEdge(g1, 0, 2);
    addEdge(g1, 1, 2);
    addEdge(g1, 1, 3);
    addEdge(g1, 2, 3);
    addEdge(g1, 3, 4);
    printf("Coloring of Graph 1 \n");
    greedyColoring(g1);
    destroyGraph(g1);

    struct Graph* g2 = createGraph(5);
    addEdge(g2, 0, 1);
    addEdge(g2, 0, 2);
    addEdge(g2, 1, 2);
    addEdge(g2, 1, 4);
    addEdge(g2, 2, 4);
    addEdge(g2, 4, 3);
    printf("\nColoring of Graph 2 \n");
    greedyColoring(g2);
    destroyGraph(g2);

    return 0;
}
