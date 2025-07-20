#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define VOCUC 999

struct Dothi
{
    int n;
    int a[MAX][MAX];
};

int LuuVet[MAX];
int ChuaXet[MAX];
int DodaiToi[MAX];
int arr[MAX];
int j;
void Nhap(Dothi &g, int n, int m)
{
    g.n = n;
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            g.a[i][j] = 0;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        g.a[u - 1][v - 1] = w;
    }
}

void Xuat(Dothi g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}
int timDuongdiNhoNhat(Dothi g)
{
    int a = -1;
    int d = VOCUC;
    for (int i = 0; i < g.n; i++)
    {
        if (ChuaXet[i] == 0 && DodaiToi[i] < d)
        {
            d = DodaiToi[i];
            a = i;
        }
    }
    return a;
}

void capNhapDuongDi(int u, Dothi g)
{
    ChuaXet[u] = 1;
    for (int v = 0; v < g.n; v++)
    {
        if (ChuaXet[v] == 0 && g.a[u][v] > 0 && g.a[u][v] < VOCUC)
        {
            if (DodaiToi[v] > DodaiToi[u] + g.a[u][v])
            {
                DodaiToi[v] = DodaiToi[u] + g.a[u][v];
                LuuVet[v] = u;
            }
        }
    }
}

void Dijkstra(Dothi g, int s, int f)
{
    for (int i = 0; i < g.n; i++)
    {
        ChuaXet[i] = 0;
        LuuVet[i] = -1;
        DodaiToi[i] = VOCUC;
    }
    DodaiToi[s] = 0;

    while (ChuaXet[f] == 0)
    {
        int u = timDuongdiNhoNhat(g);
        if (u == -1)
        {
            break;
        }
        capNhapDuongDi(u, g);
    }

    if (ChuaXet[f] == 1)
    {
        printf("%d\n", DodaiToi[f]);
        // printf("%d ", f+1);
        int i = LuuVet[f];
        arr[j++] = f + 1;
        while (i != -1)
        {
            // printf("%d ", i+1);
            arr[j++] = i + 1;
            i = LuuVet[i];
        }
        for (int i = j - 1; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
    }
    else
    {
        printf("-1");
    }
}

int Sau_nut[MAX][MAX];
int L[MAX][MAX];

void Floyd(Dothi g, int s, int f)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.a[i][j] > 0)
            {
                Sau_nut[i][j] = j;
                L[i][j] = g.a[i][j];
            }
            else
            {
                Sau_nut[i][j] = -1;
                L[i][j] = VOCUC;
            }
        }
    }

    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            for (int k = 0; k < g.n; k++)
            {
                if (L[i][j] > L[i][k] + L[k][j])
                {
                    L[i][j] = L[i][k] + L[k][j];
                    Sau_nut[i][j] = Sau_nut[i][k];
                }
            }
        }
    }

    if (Sau_nut[s][f] == -1)
    {
        printf("-1");
    }
    else
    {
        printf("%d\n", L[s][f]);

        printf("%d ", s + 1);
        //arr[j++]=s+1;
        int i = s;
        while (Sau_nut[i][f] != f)
        {
            i = Sau_nut[i][f];
            printf("%d ", i + 1);
            //arr[j++]=i+1;
        }
        /*for (int i = j - 1; i >= 0; i--)
        {
            printf("%d ", arr[i]);
        }
        */
        printf("%d ", f + 1);

    
    }
}

int main()
{
    Dothi g;
    int n, m;
    scanf("%d %d", &n, &m);
    /*for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        u--;
        v--;
        g.a[u][v] = w;
        g.a[v][u] = w;
    }*/
    Nhap(g, n, m);
    // Xuat(g);
    int s, f;
    scanf("%d %d", &s, &f);
    // Dijkstra(g, s-1, f-1);
    Floyd(g, s - 1, f - 1);
}
