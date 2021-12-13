#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e5+69;
int a[N], L[N], R[N], d[N], e[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, m, k;
    cin >> n >> m >> k;
    for(int i = 1, p = 0; i <= n; i++)
        cin >> a[i], a[i] -= p, p += a[i];
    
    for(int i = 1; i <= m; i++)
        cin >> L[i] >> R[i] >> d[i];
    
    while(k--)
    {
        int x, y;
        cin >> x >> y;
        e[x]++, e[++y]--;
    }
    for(int i = 1; i <= m; i++)
    {
        e[i] += e[i - 1];
        d[i] *= e[i];
        a[L[i]] += d[i];
        a[++R[i]] -= d[i];
    }
    for(int i = 1; i <= n; i++) {
        a[i] += a[i - 1];
        cout << a[i] << ' ';
    }
}