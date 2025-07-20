#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct {
    int data;
    int degree;
} Vertex;

typedef struct {
    int start;
    int end;
} Edge;

int graph[MAX][MAX];
Vertex vertices[MAX]; 
Edge edges[MAX]; 
int visited[MAX];

int n, m;

void initGraph() {
    int i, j;
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }
}

void addEdge(int u, int v) {
    graph[u][v] = graph[v][u] = 1;
}


int hasEulerCycle() {
    int i;
    for (i = 1; i <= n; i++) {
        if (vertices[i].degree % 2 != 0) {
            return 0; 
        }
    }
    return 1; 
}


void printEulerCycle(int start) {
    int i, v;
    for (i = 1; i <= n; i++) {
        visited[i] = 0;
    }
    int stack[MAX], top = -1;
    stack[++top] = start;
    while (top >= 0) {
        v = stack[top];
        for (i = 1; i <= n; i++) {
            if (graph[v][i] && !visited[i]) {  
                stack[++top] = i;
                visited[v] = visited[i] = 1;
                printf("%d ", v);
                break;
            }
        }

        if (i > n) {
            top--;
        }
    }
}


int main() {
    int i, u, v;
    scanf("%d %d", &n, &m);
    initGraph();
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        vertices[u].degree++;
        vertices[v].degree++;
        edges[i].start = u;
        edges[i].end = v;
    }

    if (hasEulerCycle()) {
        printf("Yes\n");
        printEulerCycle(edges[0].start);
    } else {
        printf("No\n");
    }

    return 0;
}