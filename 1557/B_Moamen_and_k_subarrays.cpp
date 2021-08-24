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
        int n, k, c = 0;   cin >> n >> k;
        pair<int, int> p[n];
        for(auto &[a, b]: p)
        {
            cin >> a;
            b = c++;
        }
        sort(p, p + n);
        c = 1;
        for(int i = 1; i < n; i++)
            c += p[i].second != p[i - 1].second + 1;
        if(c <= k)
            cout << "Yes\n";
        else
            cout << "No\n";
    }
}