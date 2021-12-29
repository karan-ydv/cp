#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 13;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n; int a[n];
    for(int &x: a)  cin >> x;


    vector<int> dp(N, 1 << 30);
    dp[0] = 0;
    for(int i = 0; i < n; i++)
    {
        vector<int> pd(dp);
        for(int j = 0; j < 512; j++)
        if(dp[j] < a[i])
            pd[j ^ a[i]] = min(pd[j ^ a[i]], a[i]);
        dp.swap(pd);
    }
    vector<int> ans;
    for(int j = 0; j < 512; j++)
        if(dp[j] < (1 << 30))
            ans.emplace_back(j);
    cout << ans.size() << '\n';
    for(int x: v)   cout << x << ' ';
}