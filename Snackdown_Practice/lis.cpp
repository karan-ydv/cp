#include <bits/stdc++.h>
using namespace std;

int lislength(vector<int> const& a) {
    vector<int> v;
    for(int x: a) {
        auto itr = lower_bound(v.begin(), v.end(), x);
        if(itr == v.end())
            v.push_back(x);
        else
            *itr = x;
    }
    return v.size();
}

vector<int> lis(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    int p[n + 1], idx[n + 1];
    d[0] = -INF;
 
    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            idx[j] = i;
            p[i] = idx[j - 1];
        }
    }
 
    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    vector<int> seq(ans);
    int i = ans;
    ans = idx[ans];
    while(i > 0 and ans < n)
    {
        seq[--i] = a[ans];
        ans = p[ans];
    }
 
    return seq;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> v(n);
    for(int &x: v)  cin >> x;
    cout << lislength(v);
}