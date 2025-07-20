#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 100

typedef struct GRAPH
{
    int n;
    int a[MAX][MAX];
} DoThi;

typedef struct EDGE
{
    int v, u;
    int value;
} C;

C T[MAX];
int ChuaXet[MAX];
int munEdges = 0;

void NhapMT(DoThi *g, int n, int m)
{
    g->n = n;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        g->a[u - 1][v - 1] = 1;
        g->a[v - 1][u - 1] = 1;
    }
}

void Ditimlienthong(DoThi g, int Nhan[], int i)
{
    for (int j = 1; j <= g.n; j++)
    {
        if (g.a[i][j] != 0 && Nhan[j] != Nhan[i])
        {
            Nhan[j] = Nhan[i];
            Ditimlienthong(g, Nhan, j);
        }
    }
}

void DFS(int v, DoThi g)
{
    ChuaXet[v] = 1;
    for (int u = 1; u <= g.n; u++)
    {
        if (g.a[v][u] != 0 && ChuaXet[u] == 0)
        {
            T[munEdges].u = v;
            T[munEdges].v = u;
            munEdges++;
            DFS(u, g);
        }
    }
}
int Xetlienthong(DoThi g)
{
    int nhan[MAX];
    for (int i = 0; i < g.n; i++)
    {
        nhan[i] = 0;
    }
    int soTPLT = 0;
    for (int i = 0; i < g.n; i++)
    {
        if (nhan[i] == 0)
        {
            soTPLT++;
            nhan[i] = soTPLT;
            Ditimlienthong(g, nhan, i);
        }
    }
    return soTPLT;
}

void CayKhung(DoThi g)
{
    if (Xetlienthong(g) == 0)
    {
        printf("-1");
    }
    else
    {
        for (int i = 1; i <= g.n; i++)
            ChuaXet[i] = 0;
        srand((unsigned)time(NULL));
        int dinhbatdau = (rand() % g.n) + 1;
        DFS(dinhbatdau, g);
        
    }
}
int main()
{
    DoThi g;
    int n, m;

    scanf("%d%d", &n, &m);

    NhapMT(&g, n, m);

    // printf("%d\n", Xetlienthong(g));

    CayKhung(g);

    return 0;
}