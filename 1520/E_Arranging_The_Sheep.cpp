#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int natural(int i) {
    return i * (i + 1) / 2;
}
int natural(int i, int j) {
    return natural(j) - natural(i - 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        string s;
        int n;	cin >> n >> s;
        vector<int> v;
        for(int i = 0; i < n; i++)
        if(s[i] == '*') v.emplace_back(i);

        int m = v.size();
        if(m == 0)
        {
            cout << "0\n";
            continue;
        }
        int pref[m] = {0};
        partial_sum(v.begin(), v.end(), pref);

        auto f = [&](int i)
        {
            int beg = 0, end = m - 1, ans = m;
            while(beg <= end)
            {
                int mid = (beg + end) >> 1;
                if(v[mid] > mid + i)
                    ans = mid, end = mid - 1;
                else
                    beg = mid + 1;
            }
            return ans;
        };     

        auto cost = [&](int i)
        {
            if(i + m > n)   return (int)1e18;
            int j = f(i);
            // cerr << j << '\n';
            if(j == 0)
            {
                // cerr << i << ' ' << pref[m - 1] - natural(i, i + m - 1) << '\n';
                return pref[m - 1] - natural(i, i + m - 1);
            }
            if(j == m)
            {
                // cerr << i << ' ' << natural(i, i + m - 1) - pref[m - 1] << '\n';
                return natural(i, i + m - 1) - pref[m - 1];
            }
            int cst = 0;
            cst += natural(i, i + j - 1) - pref[j - 1];
            cst += pref[m - 1] - pref[j - 1] - natural(i + j, i + m - 1);
            // cerr << i << ' ' << cst << '\n';
            return cst;
        };

        int ans = 1e18;
        for(int i = 0; i < n; i++)
        {
            ans = min(ans, cost(i));
        }
        cout << ans << '\n';
    }
}