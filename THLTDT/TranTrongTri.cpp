#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

struct Dothi
{
    int n;
    int a[MAX][MAX];
};

struct Canh
{
    int dinhDau;
    int dinhCuoi;
    int trongso;
};

struct STACK
{
    int arr[MAX];
    int size;
};

int DocMaTranKe(const char TenFile[], Dothi &g)
{
    FILE *f = fopen(TenFile, "rt");
    if (f == NULL)
    {
        printf("Khong mo file\n");
        return 0;
    }

    fscanf(f, "%d", &g.n);

    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            fscanf(f, "%d", &g.a[i][j]);
        }
    }

    fclose(f);

    return 1;
}

void XuatMatranKe(Dothi g)
{
    printf("So dinh: %d\n", g.n);
    printf("Ma tran: \n");
    for (int i = 0; i < g.n; i++)
    {
        printf("\t");
        for (int j = 0; j < g.n; j++)
        {
            printf("%3d", g.a[i][j]);
        }
        printf("\n");
    }
}

int KTdothiVohuong(Dothi g)
{
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (g.a[i][j] != g.a[j][i])
                return 0;
        }
    }
    return 1;
}

int KTdothicoKhuyen(Dothi g)
{
    for (int i = 0; i < g.n; i++)
    {
        if (g.a[i][i] != 0)
        {
            return 0;
        }
    }
    return 1;
}

void Khoitao(STACK &s)
{
    s.size = 0;
}

void Daygiaitri(STACK &s, int value)
{
    if (s.size +1 > 100)
    {
        return;
    }
    s.arr[s.size] = value;
        s.size++;
}

/*void Hienstack(STACK &s)
{
    for (int i = 0; i < s.size; i++)
    {
        printf("%d ", s.arr[i]);
    }
    printf("\n");
}*/ 

int Bacdinh(int v,Dothi g)
{
    int bac = 0;
    for (int i = 0; i < g.n; i++)
    {
        if (g.a[v][i] != 0)
            bac++;
    }
    return bac;
}

void Timduongdi(int x, Dothi &g, STACK &s)
{
    for (int j = 0; j < g.n; j++)
    {
        if (g.a[x][j] != 0)
        {
            g.a[x][j] = 0;
            g.a[j][x] = 0;
            Timduongdi(j, g, s);
        }
    }
}

int KTchutrinhEluer(Dothi g)
{
    int x = 0;
    for (int i = 0; i < g.n; i++)
    {
        if (Bacdinh(i, g) > 0)
        {
            x = i;
            break;
        }
    }
    Dothi temp = g;
    STACK s;
    Khoitao(s);
    
    Timduongdi(x, temp, s);
    for (int i = 0; i < g.n; i++)
    {
        for (int j = 0; j < g.n; j++)
        {
            if (temp.a[i][j] != 0)
            {
                return 0;
            }
        }
    }

    if (s.arr[0] != s.arr[s.size - 1])
    {
        return 0;
    }

    printf("Chu trinh Euler: \n");
    for (int i = s.size - 1; i >= 0; i--)
    {
        printf("%d ", s.arr[i]);
    }

    return 1;
}

#define inputfile "D:\\THLTDT\\text.txt"

int main()
{
    Dothi g;
    if (DocMaTranKe(inputfile, g) == 1)
    {
        printf("1\n");
    }
    else
    {
        printf("0\n");
    }
    XuatMatranKe(g);

    printf("Do thi co huong: %s\n",
           KTdothiVohuong(g) == 1 ? "vo huong" : "co huong");
    printf("Do thi co khuyen: %s\n",
           KTdothicoKhuyen(g) == 1 ? "co khuyen" : "khong khuyen");
    if (KTchutrinhEluer(g) == 0)
    {
        printf("0\n");
    }
    return 0;
}
