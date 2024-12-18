//WAP to perform graphs creation and traversal.

#include <stdio.h>
#include <stdlib.h>

#define MAX 20

struct Graph {
    int adjMatrix[MAX][MAX];
    int numVertices;
};

void initializeGraph(struct Graph* g, int vertices) {
    g->numVertices = vertices;
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            g->adjMatrix[i][j] = 0;
        }
    }
}

void addEdge(struct Graph* g, int start, int end) {
    g->adjMatrix[start][end] = 1;
    g->adjMatrix[end][start] = 1;  // For undirected graph
}

void DFS(struct Graph* g, int start, int visited[]) {
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < g->numVertices; i++) {
        if (g->adjMatrix[start][i] == 1 && !visited[i]) {
            DFS(g, i, visited);
        }
    }
}

void BFS(struct Graph* g, int start) {
    int visited[MAX] = {0};
    int queue[MAX], front = 0, rear = 0;
    
    visited[start] = 1;
    queue[rear++] = start;
    
    while (front != rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 0; i < g->numVertices; i++) {
            if (g->adjMatrix[node][i] == 1 && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
}

int main() {
    struct Graph g;
    int vertices, edges, start, u, v;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    initializeGraph(&g, vertices);

    printf("Enter the number of edges: ");
    scanf("%d", &edges);

    printf("Enter the edges (u v):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        addEdge(&g, u, v);
    }

    printf("Enter the starting vertex for DFS and BFS: ");
    scanf("%d", &start);

    int visited[MAX] = {0};
    
    printf("DFS traversal: ");
    DFS(&g, start, visited);

    printf("\nBFS traversal: ");
    BFS(&g, start);

    return 0;
}

//Theory :

/*
    Theory of Graph Creation and Traversal (DFS and BFS):

    A graph is a non-linear data structure consisting of nodes (vertices) and edges (connections between nodes). 
    It is used to represent relationships or connections between entities.

    1. Graph Representation:
       - A graph can be represented in various ways, including adjacency matrix, adjacency list, and edge list.
       - In this program, we use an adjacency matrix to represent the graph, where `adjMatrix[i][j] = 1` indicates an edge between vertex `i` and vertex `j`. 
       - For an undirected graph, the matrix is symmetric (`adjMatrix[i][j] = adjMatrix[j][i]`).

    2. Depth First Search (DFS):
       - DFS is a traversal technique that explores the graph as far as possible along each branch before backtracking.
       - It starts at the root (or any arbitrary node) and explores as deep as possible before backtracking.
       - DFS can be implemented using recursion or using a stack data structure.
       - In DFS, nodes are visited in a "depth-first" manner, where the algorithm moves along the branches of the tree (or graph) as deeply as possible before visiting other branches.

       Algorithm for DFS:
       - Start at the root or any unvisited node.
       - Mark the current node as visited.
       - For each adjacent node, if it is not visited, recursively call DFS for that node.
       - This process continues until all nodes are visited.

       Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

    3. Breadth First Search (BFS):
       - BFS is a traversal technique that explores all the neighbors of a node before moving to the next level of neighbors.
       - BFS uses a queue to keep track of the nodes to visit next.
       - BFS visits nodes level by level, starting from a given source node.

       Algorithm for BFS:
       - Start at the root (or any arbitrary node).
       - Mark the node as visited and enqueue it.
       - While the queue is not empty, dequeue a node, visit its unvisited neighbors, and enqueue them.
       - Continue this process until all nodes are visited.

       Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.

    4. Applications of Graph Traversal:
       - Graph traversal algorithms are widely used in various applications, including:
         - Finding the shortest path in an unweighted graph.
         - Checking for connectivity between nodes.
         - Solving problems such as maze solving and circuit design.
         - Analyzing networks and relationships in social networks or web pages.
*/
