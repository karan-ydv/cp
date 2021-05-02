#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int u[n], s[n];
        for(int &x: u)  cin >> x;
        for(int &x: s)  cin >> x;

        int sum = accumulate(s, s + n, 0ll);
        vector<int> ans(n + 1, sum);

        map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[u[i]].emplace_back(s[i]);
        }
        vector<int> suff[mp.size()];
        int A[n + 2] = {0};
        for(auto &[x, y]: mp)
        {
            sort(y.begin(), y.end());
            int tmp = 0;
            int m = y.size();
            int pref[m + 1] = {0};
            for(int i = 1; i <= m; i++)
                pref[i] = pref[i - 1] + y[i - 1];
            
            for(int i = 1; i <= m; i++)
            {
                if(m % i != 0)
                {
                    ans[i] -= pref[m % i];
                }
            }
            A[m + 1] += pref[m];
        }
        partial_sum(A, A + n + 2, A);
        for(int i = 1; i <= n; i++) cout << ans[i] - A[i] << " \n"[i == n];
    }
}