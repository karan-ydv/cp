#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int X[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        if (u > v)
            swap(u, v);
        X[u]++;
        if (X[u] == 1)
            cnt++;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            if (b > c)
                swap(b, c);
            X[b]++;
            if (X[b] == 1)
                cnt++;
        }
        if (a == 2)
        {
            cin >> b >> c;
            if (b > c)
                swap(b, c);
            X[b]--;
            if (X[b] == 0)
                cnt--;
        }
        if (a == 3)
        {
            cout << n - cnt << '\n';
        }
    }
}