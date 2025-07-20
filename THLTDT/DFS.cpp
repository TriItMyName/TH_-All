#include <stdio.h>
#include <stdlib.h>

#define MAX 50

struct DoThi
{
    int x;
    int a[MAX][MAX];
};

void NhapMT(DoThi *g, int n, int m)
{
    g->x = n;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
       
        g->a[u - 1][v - 1] = 1;
        g->a[v - 1][u - 1] = 1;
    }
}

void XuatMT(DoThi g)
{
    for (int i = 0; i < g.x; i++)
    {
        for (int j = 0; j < g.x; j++)
        {
            printf("%d ", g.a[i][j]);
        }
        printf("\n");
    }
}

int LuuVet[MAX];
int ChuaXet[MAX];
int kp[MAX]; int j;
void DFS(int v, DoThi g)
{
    ChuaXet[v] = 1;
    //printf("%d ", v + 1); 
    for (int i = 0; i < g.x; i++)
    {
        if (g.a[v][i] != 0 && ChuaXet[i] == 0)
        {
            LuuVet[i] = v;
            DFS(i, g);
        }
    }
}

void DuyetDFS(int s, int f, DoThi g)
{
    for (int i = 0; i < g.x; i++)
    {
        ChuaXet[i] = 0;
    }
    for (int i = 0; i < g.x; i++)
    {
        LuuVet[i] = -1;
    }
    DFS(s -1, g); 
    if (ChuaXet[f - 1] == 1)
    {
        int i = f -1;
        //printf("%d ", i+1);
        kp[j]=i; j++;
        while (i != s-1)
        {
            i = LuuVet[i];
            //printf("%d ", i+1);
            kp[j]=i; j++;
            
        }
        for(i=j-1;i>=0;i--)
                printf("%d ",kp[i]+ 1);
    }
    else
    {
        printf("Not Found");
    }
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    DoThi g;

    NhapMT(&g, n, m);

    int d, c;
    scanf("%d %d", &d, &c);

    
    DuyetDFS(d, c, g);

    return 0;
}