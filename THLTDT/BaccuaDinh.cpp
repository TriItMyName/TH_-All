#include <stdio.h>

#define MAX_VERTICES 100

// Khai báo biểu diễn đồ thị
int graph[MAX_VERTICES][MAX_VERTICES];
int degrees[MAX_VERTICES];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Khởi tạo ma trận đồ thị và mảng bậc
    for (int i = 0; i < n; i++) {
        degrees[i] = 0;
        for (int j = 0; j < n; j++) {
            graph[i][j] = 0;
        }
    }
    
    // Nhập thông tin về các cạnh của đồ thị
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        graph[u - 1][v - 1] = 1;
        graph[v - 1][u - 1] = 1;
        degrees[u - 1]++;
        degrees[v - 1]++;
    }

    // In ra bậc của mỗi đỉnh
    for (int i = 0; i < n; i++) {
        printf("%d %d\n", i + 1, degrees[i]);
    }

    return 0;
}