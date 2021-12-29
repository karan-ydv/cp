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
        int n, k;   cin >> n >> k;
        vector<int> a(n);
        for(int &x: a)  cin >> x;
        if(is_sorted(a.begin(), a.end()))
        {
            cout << "0\n";
            continue;
        }
        int cnt = 0;
        for(int i = k; i < n; i++) {
            cnt += a[i] == i + 1;
        }
        bool one = (cnt == n - k);
        for(int i = k; !one and i < n; i++) {
            cnt -= a[i] == i + 1;
            cnt += a[i - k] == i - k + 1;
            one = (cnt == n - k);
        }
        if(one)
        {
            cout << "1\n";
            continue;
        }
        int l = 0, r = n - 1;
        for(; l < n; l++)
            if(a[l] != l + 1)   break;
        for(; r > -1; r--)
            if(a[r] != r + 1)   break;
        
        vector<int> b(a), c(a);
        sort(b.begin() + l, b.begin() + l + k);
        sort(b.begin() + r - k + 1, b.begin() + r + 1);
        sort(c.begin() + r - k + 1, c.begin() + r + 1);
        sort(c.begin() + l, c.begin() + l + k);

        if(is_sorted(b.begin(), b.end()) or is_sorted(c.begin(), c.end()))
            cout << "2\n";
        else
            cout << "3\n";
    }
}