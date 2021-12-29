#include <bits/stdc++.h>
using namespace std;

int t, n, b, i, x;
int main()
{
    cin >> t;
    while(t--)
    {
        cin >> n >> b;
        vector<int> a(4, 1e8), p(n);
        for(int &x: p) cin >> x;
        i = 0;
        while(i < n)
            cin >> x, a[x] = min(a[x], p[i++]);
        for(int x: a) b -= x;
        cout << (b < 0 ? "no" : "yes");
    }
}