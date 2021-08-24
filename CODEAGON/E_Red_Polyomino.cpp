#include <bits/stdc++.h>
#define int int64_t
#define uint uint64_t
using namespace std;

int n;
unordered_set<uint> SET;
bool valid(int i, int j)
{
    return 0 <= i and i < n and 0 <= j and j < n;
}

pair<int, int> d4[] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
void fun(array<char, 64> b, int k)
{
    if(k == 0)
    {
        uint f = 0;
        for(uint i = 0, x = 1; i < n * n; i++, x <<= 1) {
            // if(i % n == 0)
            // cerr << '\n';
            // cerr << b[i];
            if(b[i] == '@') f |= x;
        }
        // cerr << '\n';
        SET.insert(f);
        return;
    }
    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(b[i * n + j] == '.')
        for(auto [dx, dy]: d4)
        {
            int x = i + dx, y = j + dy;
            if(valid(x, y) and b[x * n + y] == '@')
            {
                b[i * n + j] = '@';
                fun(b, k - 1);
                b[i * n + j] = '.';
            }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    array<char, 64> b;
    int k;   cin >> n >> k;
    string s[n];
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < n; j++)
            b[i * n + j] = s[i][j];
    }

    for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++)
    {
        if(b[i * n + j] == '.')
        {
            b[i * n + j] = '@';
            fun(b, k - 1);
            b[i * n + j] = '.';
        }
    }

    cout << SET.size();
}