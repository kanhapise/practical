//AIM : WAP to implement graph prims algorithm and kruskal algorithm for finding minimum spanning tree.


#include <stdio.h>
#include <stdlib.h>

#define INF 999999
#define MAX 20

// Structure for Kruskal's Algorithm - for Edge representation
struct Edge {
    int u, v, weight;
};

struct Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
};

// Function to find the Minimum Key Node for Prim's Algorithm
int minKey(int key[], int mstSet[], int numVertices) {
    int min = INF, minIndex;
    for (int v = 0; v < numVertices; v++) {
        if (mstSet[v] == 0 && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

// Prim's Algorithm to find MST
void primMST(struct Graph *g) {
    int parent[MAX], key[MAX], mstSet[MAX];
    int numVertices = g->numVertices;

    for (int i = 0; i < numVertices; i++) {
        key[i] = INF;
        mstSet[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (int count = 0; count < numVertices - 1; count++) {
        int u = minKey(key, mstSet, numVertices);
        mstSet[u] = 1;

        for (int v = 0; v < numVertices; v++) {
            if (g->adjMatrix[u][v] != 0 && mstSet[v] == 0 && g->adjMatrix[u][v] < key[v]) {
                parent[v] = u;
                key[v] = g->adjMatrix[u][v];
            }
        }
    }

    printf("Prim's MST:\n");
    for (int i = 1; i < numVertices; i++) {
        printf("%d - %d: %d\n", parent[i], i, g->adjMatrix[i][parent[i]]);
    }
}

// Function to find the root of a set in Kruskal's Algorithm (for Union-Find)
int find(int parent[], int i) {
    if (parent[i] == -1) {
        return i;
    }
    return find(parent, parent[i]);
}

// Function to perform Union of two sets in Kruskal's Algorithm
void unionSets(int parent[], int x, int y) {
    parent[x] = y;
}

// Kruskal's Algorithm to find MST
void kruskalMST(struct Graph *g) {
    int numEdges = 0, mstEdges = 0;
    struct Edge edges[MAX * MAX];
    int parent[MAX];

    for (int i = 0; i < g->numVertices; i++) {
        parent[i] = -1;
    }

    // Store all edges
    for (int i = 0; i < g->numVertices; i++) {
        for (int j = i + 1; j < g->numVertices; j++) {
            if (g->adjMatrix[i][j] != 0) {
                edges[numEdges].u = i;
                edges[numEdges].v = j;
                edges[numEdges].weight = g->adjMatrix[i][j];
                numEdges++;
            }
        }
    }

    // Sort edges by weight (Bubble Sort for simplicity)
    for (int i = 0; i < numEdges - 1; i++) {
        for (int j = 0; j < numEdges - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }

    printf("Kruskal's MST:\n");

    // Process each edge
    for (int i = 0; i < numEdges; i++) {
        int x = find(parent, edges[i].u);
        int y = find(parent, edges[i].v);

        if (x != y) {
            printf("%d - %d: %d\n", edges[i].u, edges[i].v, edges[i].weight);
            unionSets(parent, x, y);
            mstEdges++;
        }

        if (mstEdges == g->numVertices - 1) {
            break;
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, u, v, weight;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    g.numVertices = vertices;

    // Initialize adjacency matrix with 0s
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g.adjMatrix[i][j] = 0;
        }
    }

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v weight):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d %d", &u, &v, &weight);
        g.adjMatrix[u][v] = weight;
        g.adjMatrix[v][u] = weight;
    }

    primMST(&g);
    kruskalMST(&g);

    return 0;
}


//THEORY:
/*
1. Prim's Algorithm:
Concept: Prim's algorithm is a greedy algorithm that finds a Minimum Spanning Tree (MST) for a connected, weighted graph. It starts from an arbitrary vertex and grows the MST by adding the smallest edge that connects a vertex in the MST to a vertex outside of it.
Algorithm:
- Start from an arbitrary vertex.
- Maintain a set of vertices included in the MST.
- At each step, add the minimum-weight edge that connects a vertex in the MST to a vertex outside it.
- Repeat this until all vertices are included in the MST.
Time Complexity: O(V²) where V is the number of vertices, using an adjacency matrix.
Use: Efficient for dense graphs.

2. Kruskal's Algorithm:
Concept: Kruskal's algorithm is a greedy algorithm that finds a Minimum Spanning Tree (MST) by sorting all edges in non-decreasing order of their weights and adding edges to the MST as long as they don't form a cycle, using a union-find data structure.
Algorithm:
- Sort all the edges in the graph by weight.
- Start adding edges to the MST from the sorted list, ensuring no cycles are formed by using a union-find data structure.
- Continue adding edges until the MST contains (V-1) edges.
Time Complexity: O(E log E) where E is the number of edges.
Use: Efficient for sparse graphs.
*/


