#include <bits/stdc++.h>
#define int int64_t
using namespace std;

// maintains sum of n largest elements in the set
struct SetMax {
    int n, sum;
    multiset<int> set;
    SetMax(int n) : n(n), sum(0) {}
    void insert(int x)
    {
        sum += x;
        set.insert(x);
        if(set.size() > n)
        {
            sum -= *set.begin();
            set.erase(set.begin());
        }
    }
    void remove(int x)
    {
        auto itr = set.find(x);
        if(itr != set.end())
        {
            sum -= x;
            set.erase(itr);
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, x, y;    cin >> n >> x >> y;
        int a[n];       for(int &x: a) cin >> x;
        if(y >= n)
        {
            cout << n << '\n';
            continue;
        }
        int ans = y, sum = 0;
        SetMax s(y);
        for(int R = 0, L = -1; R < n; R++)
        {
            sum += a[R];
            s.insert(a[R]);
            while(sum - s.sum > x and L < R)
            {
                sum -= a[++L];
                s.remove(a[L]);
            }
            ans = max(ans, R - L);
        }
        cout << ans << '\n';
    }
}