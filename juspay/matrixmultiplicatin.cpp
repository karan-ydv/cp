#include <bits/stdc++.h>
using namespace std;

struct Matrix
{
    vector<vector<int>> M;
    int R, C;
    Matrix(int n, int m)
    {
        R = n, C = m;
        M = vector<vector<int>>(n, vector<int>(m));
    }
    Matrix Multiply(const Matrix& b)
    {
        assert(C == b.R);
        Matrix c(R, b.C);
        for(int i = 0; i < R; i++)
        for(int j = 0; j < C; j++)
        for(int k = 0; k < b.R; k++)
        {
            c.M[i][j] += M[i][k] * b.M[k][j];
        }
        return c;
    }
    void print()
    {
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++)
                cerr << M[i][j] << " \n"[j == C - 1];
        }
    }
};

int main()
{
    int R1, C1, R2, C2;
    cin >> R1 >> C1;
    Matrix a(R1, C1);
    for(int i = 0; i < R1; i++) {
        for(int j = 0; j < C1; j++)
            cin >> a.M[i][j];
    }
    cin >> R2 >> C2;
    Matrix b(R1, C1);
    for(int i = 0; i < R2; i++) {
        for(int j = 0; j < C2; j++)
            cin >> b.M[i][j];
    }
    Matrix c = a.Multiply(b);
    a.print();
    b.print();
    c.print();
}