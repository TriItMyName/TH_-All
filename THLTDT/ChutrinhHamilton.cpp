#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int n, m;
int graph[MAX][MAX];
int path[MAX];
int visited[MAX];

void inputGraph() {
   
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u][v] = 1;
        graph[v][u] = 1;
    }
}

void printHamiltonianCycle() {
 
    for (int i = 1; i <= n; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[1]);  
}

int is_valid(int v, int pos) {
   
    if (graph[path[pos - 1]][v] == 0) {
        return 0;
    }

    
    for (int i = 1; i <= pos; i++) {
        if (path[i] == v) {
            return 0;
        }
    }

    return 1;
}

int hamiltonian_cycle_util(int pos) {
    if (pos == n + 1) {
        
        return 1;
    }

    for (int v = 1; v <= n; v++) {
        if (is_valid(v, pos)) {
            path[pos] = v;

            if (hamiltonian_cycle_util(pos + 1)) {
                return 1;
            }

            
            path[pos] = 0;
        }
    }

    return 0;
}

void findHamiltonianCycle() {
    for (int i = 1; i <= n; i++) {
        path[i] = 0;
    }

    path[1] = 1; 

    if (!hamiltonian_cycle_util(2)) {
        printf("-1\n");
    } else {
        printHamiltonianCycle();
    }
}

int main() {
    inputGraph();
    findHamiltonianCycle();

    return 0;
}
