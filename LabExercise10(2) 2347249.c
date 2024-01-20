#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// structure to represent an edge
struct Edge {
    int src, dest, weight;
};

// structure to represent a graph
struct Graph {
    int V, E;
    struct Edge* edge;
};

// create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

// utility function to find the subset of an element i
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// utility function to do union of two subsets
void Union(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// compare function used by qsort to sort edges in ascending order
int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

// function to construct MST using Kruskal's algorithm
void kruskalMST(struct Graph* graph) {
    int V = graph->V;
    struct Edge result[V];
    int e = 0;
    int i = 0;

    // Step 1: Sort all the edges in non-decreasing order of their weight
    qsort(graph->edge, graph->E, sizeof(graph->edge[0]), compare);

    // Allocate memory for creating V subsets
    int* parent = (int*)malloc(V * sizeof(int));
    memset(parent, -1, sizeof(int) * V);

    // Number of edges to be taken is equal to V-1
    while (e < V - 1 && i < graph->E) {
        // Step 2: Pick the smallest edge. Increment index for the next iteration
        struct Edge next_edge = graph->edge[i++];

        int x = find(parent, next_edge.src);
        int y = find(parent, next_edge.dest);

        // If including this edge doesn't cause a cycle, include it in the result
        if (x != y) {
            result[e++] = next_edge;
            Union(parent, x, y);
        }
    }

    // Print the constructed MST
    printf("Edge   Weight\n");
    for (i = 0; i < e; i++)
        printf("%d - %d    %d \n", result[i].src, result[i].dest, result[i].weight);

    free(parent);
}

int main() {
    int V = 5; // Number of vertices in the graph
    int E = 7; // Number of edges in the graph
    struct Graph* graph = createGraph(V, E);

    // Example graph
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 2;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 3;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 4;
    graph->edge[3].weight = 5;

    graph->edge[4].src = 2;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 7;

    graph->edge[5].src = 3;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 9;

    graph->edge[6].src = 2;
    graph->edge[6].dest = 3;
    graph->edge[6].weight = 8;

    kruskalMST(graph);

    return 0;
}

