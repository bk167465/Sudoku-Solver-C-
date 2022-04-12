#include <bits/stdc++.h>
using namespace std;

#define UNASSIGNED 0

bool isSafe(int a[9][9], int r, int c, int n);

bool Find(int a[9][9], int &r, int &c);

bool fun(int a[9][9])
{
    int r, c;
    if (!Find(a, r, c))
        return true;
    for (int n = 1; n <= 9; n++)
    {
        if (isSafe(a, r, c, n))
        {
            a[r][c] = n;
            if (fun(a))
                return true;
            a[r][c] = UNASSIGNED;
        }
    }
    return false;
}

bool Find(int a[9][9], int &r, int &c)
{
    for (r = 0; r < 9; r++)
        for (c = 0; c < 9; c++)
            if (a[r][c] == UNASSIGNED)
                return true;
    return false;
}

bool Row(int a[9][9], int r, int n)
{
    for (int c = 0; c < 9; c++)
        if (a[r][c] == n)
            return true;
    return false;
}

bool Col(int a[9][9], int c, int n)
{
    for (int r = 0; r < 9; r++)
        if (a[r][c] == n)
            return true;
    return false;
}

bool Box(int a[9][9], int R, int C, int n)
{
    for (int r = 0; r < 3; r++)
        for (int c = 0; c < 3; c++)
            if (a[r + R][c + C] == n)
                return true;
    return false;
}

bool isSafe(int a[9][9], int r, int c, int n)
{
    return !Row(a, r, n) && !Col(a, c, n) && !Box(a, r - r % 3, c - c % 3, n) && a[r][c] == UNASSIGNED;
}

int main()
{
    int a[9][9];
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> a[i][j];
        }
    }
    if (fun(a) == true)
    {
        for (int r = 0; r < 9; r++)
        {
            for (int c = 0; c < 9; c++)
            {
                cout << a[r][c] << " ";
            }
            cout << endl;
        }
    }
    else
        cout << "No solution exists";
    return 0;
}