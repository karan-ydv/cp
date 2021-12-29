#include <bits/stdc++.h>
using namespace std;

const int N = 202;
int dp[N][N][N];

int lislength(int a[], int n) {
    vector<int> v;
    for(int i = 0; i < n; i++) {
        int x = a[i];
        auto itr = upper_bound(v.begin(), v.end(), x);
        if(itr == v.end())
            v.emplace_back(x);
        else
            *itr = x;
    }
    return (int) v.size();
}

void solve()
{
    int n, k;   cin >> n >> k;
    int a[n];   for(int &x: a)  cin >> x;
    sort(a, a + n, greater());
    if(lislength(a, n) > k)
        return cout << "-1\n", void();
    
    for(int i = n - 1; i > 0; i--)
    while(true)
    {
        int c = 0;
        for(int j = i; j > 0; j--)
        {
            if(a[j] >= a[j - 1])    continue;
            swap(a[j], a[j - 1]);
            if(lislength(a, n) > k)
                swap(a[j], a[j - 1]);
            else
                c++;
        }
        if(c == 0)  break;
    }
    for(int x: a)   cout << x << ' ';
    cout << '\n';
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--) solve();
}