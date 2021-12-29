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
        int n, k;   cin >> n;
        int a[n];   for(int &x: a)  cin >> x;
        cin >> k;
        vector<int> A[k];
        for(int i = 0; i < n; i++)
        {
            vector<int> &v = A[i % k];
            auto itr = upper_bound(v.begin(), v.end(), a[i]);
            if(itr == v.end())
                v.push_back(a[i]);
            else
                *itr = a[i];
        }
        int ans = n;
        for(int i = 0; i < k; i++)
            ans -= A[i].size();
        cout << ans << '\n';
    }
}