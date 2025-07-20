#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define MAX 50

struct DoThi
{
    int x;
    int a[MAX][MAX];
};

void NhapMT(DoThi *g, int n, int m)
{
    g->x = n;

    cout << "Nhap ma tran ke cua do thi:\n";
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        // Chú ý: Đây là đồ thị vô hướng, nên ta cần cập nhật cả hai chiều của ma trận.
        g->a[u - 1][v - 1] = 1;
        g->a[v - 1][u - 1] = 1;
    }
}

void DFS(int v, DoThi g, vector<bool> &daTham, vector<int> &ketQua)
{
    daTham[v] = true;

    for (int i = 0; i < g.x; i++)
    {
        if (g.a[v][i] != 0 && !daTham[i])
        {
            DFS(i, g, daTham, ketQua);
        }
    }

    ketQua.push_back(v + 1);
}


void DuyetDFS(int s, int f, DoThi g)
{
    vector<bool> daTham(g.x, false);
    vector<int> ketQua;

    DFS(s - 1, g, daTham, ketQua);

    if (daTham[f - 1])
    {
        
        sort(ketQua.begin(), ketQua.end());

        for (int i : ketQua)
        {
            cout << i << " ";
        }
    }
    else
    {
        cout << "Not Found";
    }
}
int main()
{
    int n, m;
    cout << "Nhap kich thuoc ma tran ke: ";
    cin >> n >> m;

    DoThi g;

    // Input the graph
    NhapMT(&g, n, m);

    int source, destination;
    cout << "\nNhap dinh bat dau va ket thuc (S F): ";
    cin >> source >> destination;

    // Perform DFS and print the result
    DuyetDFS(source, destination, g);

    return 0;
}
