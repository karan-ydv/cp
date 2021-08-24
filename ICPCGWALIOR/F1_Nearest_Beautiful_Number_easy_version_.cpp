#include <bits/stdc++.h>
#define int int64_t
using namespace std;

vector<int> a, b;
int n, k, u, v;

void fun(int x)
{
    b.emplace_back(x);
    if (x >= 1e9)
        return;
    fun(x * 10 + u);
    fun(x * 10 + v);
}

void precum()
{
    for (int i = 1; i <= 9; i++)
    {
        u = 0, v = i, fun(i);
        a.emplace_back(i);
        int x = i;
        while (x <= 1e9)
        {
            (x *= 10) += i;
            a.emplace_back(x);
        }
    }

    for (int i = 1; i <= 9; i++)
        for (int j = i + 1; j <= 9; j++)
        {
            u = i, v = j;
            fun(0);
        }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precum();
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k == 1)
            cout << *lower_bound(a.begin(), a.end(), n);
        else
            cout << *lower_bound(b.begin(), b.end(), n);
        cout << '\n';
    }
}