#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 1e4+5;
int a[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, sum = 0;  cin >> n;
        for(int i = 1; i <= n; i++)
            cin >> a[i], sum += a[i];
        if(sum % n)
        {
            cout << "-1\n";
            continue;
        }
        vector<tuple<int, int, int>> ans;
        for(int i = 2; i <= n; i++)
        {
            if(a[i] % i)
                ans.emplace_back(1, i, i - a[i] % i);
            ans.emplace_back(i, 1, (a[i] + i - 1) / i);
        }
        for(int i = 2; i <= n; i++)
            ans.emplace_back(1, i, sum / n);
        cout << ans.size() << '\n';
        for(auto [a, b, c]: ans)
            cout << a << ' ' << b << ' ' << c << '\n';
    }
}