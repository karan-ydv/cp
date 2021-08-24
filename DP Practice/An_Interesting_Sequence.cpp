#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int ans[N], spf[N];
void sieve()
{
    iota(spf, spf + N, 0);
    for(int i = 4; i <= N; i += 2)  spf[i] = 2;
    for(int i = 3; i * i <= N; i += 2)
    {
        if(spf[i] == i)	for(int j = i * i; j < N; j += i)
        if(spf[j] == j)	spf[j] = i;
    }
}
vector<pair<int, int>> factors(int n) {
    vector<pair<int, int>> f;
    while(n != 1)
    {
        int p = spf[n], c = 0;
        while(spf[n] == p)
            c++, n /= p;
        f.emplace_back(p, c);
    }
    return f;
}
void precumpute()
{
    int x = 5;
    for(int i = 1; i < N; i++, x += 4)
    {
        ans[i] = 2 * i - 1 + x;
        for(int j = 2; j * j <= x; j++) if(x % j == 0)
        {
            int f;
            ans[i] += j * f - f;
            if(j * j != x)
            {
                
                ans[i] += x / j * f - f;
            }
        }
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    precumpute();
    int t; cin >> t;
    while(t--)
    {
        int k;  cin >> k;
        cout << ans[k] << '\n';
    }
}