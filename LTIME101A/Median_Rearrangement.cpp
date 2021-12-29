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
        int a[n * n];
        for(int &x: a)  cin >> x;
        sort(a, a + n * n);
        int x = ((n + 2) / 2 - 1);
        int beg = x, end = n * x, ans = -1;
        auto fun = [&](int p)
        {
            int sum = 0;
            unordered_set<int> taken;
            for(int i = 0, k = 0; i < n; i++)
            {
                for(int j = 0; j < x; j++, k++)
                    while(taken.count(k)) k++;
                if(p < k) p = k;
                sum += a[p];
                taken.insert(p++);
            }
            return sum <= k;
        };
        while(beg <= end)
        {
            int mid = (beg + end) / 2;
            if(fun(mid))
                ans = a[mid], beg = mid + 1;
            else
                end = mid - 1;
        }
        cout << ans << '\n';
    }
}

