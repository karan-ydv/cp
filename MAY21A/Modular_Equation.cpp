#include <bits/stdc++.h>
using namespace std;

const int N = 5e5+5;
bitset<N> flag;
vector<int> divs[N];

void cum()
{
    for(int i = 1; i < N; i++)
        for(int j = i; j < N; j += i)
            if(flag[j]) divs[j].emplace_back(i);
}

void foreplay(int n, int m)
{
    for(int b = 2; b <= n; b++)
    {
        int x = m - m % b;
        if(b > m)   break;
        flag[x] = 1;
    }
}

int64_t afterplay(int n, int m)
{
    int64_t ans = 0;
    for(int b = 2; b <= n; b++)
    {
        int x = m - m % b;
        if(b > m)
        {
            ans += 1LL * n * (n - 1) / 2;
            ans -= 1LL * (b - 1) * (b - 2) / 2;
            break;
        }
        ans += lower_bound(divs[x].begin(), divs[x].end(), b) - divs[x].begin();
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    vector<pair<int, int>> v(t);
    for(auto &[n, m]: v) cin >> n >> m, foreplay(n, m);
    cum();
    for(auto [n, m]: v) cout << afterplay(n, m) << '\n';
}