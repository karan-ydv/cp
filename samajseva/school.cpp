#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("school.in", "r", stdin);
    int t;	cin >> t;
    while(t--)
    {
        int n, s, x;
        cin >> n >> s >> x;
        int a[n];   for(int &x: a)  cin >> x;
        int e1[n];  for(int &x: e1) cin >> x;
        int b1[n];  for(int &x: b1) cin >> x;
        int e2[n];  for(int &x: e2) cin >> x;
        int b2[n];  for(int &x: b2) cin >> x;
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int eat = e1[i] + e2[i];
            if(a[i] + b1[i] + b2[i] >= s)
                eat -= x;
            int skip = e2[i];
            if(a[i] + b2[i] >= s)
                skip -= x;
            ans += max(eat, skip);
        }
        cout << ans << '\n';
    }
}