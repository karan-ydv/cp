#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n; char c; string s;
        cin >> n >> c >> s;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            if(s[i] != c)   v.emplace_back(i + 1);
        }
        if(v.empty())
            cout << "0\n";
        else if(v.back() != n)
            cout << "1\n" << n << '\n';
        else
        {
            bool f[n + 1]{1};
            for(int x: v)
            {
                for(int i = 1; i * i <= x; i++)
                if(x % i == 0) f[i] = f[x / i] = 1;
            }
            int x = int (find(f, f + n + 1, 0) - f);
            if(x == n + 1)
            {
                cout << "2\n" << n << ' ';
                for(int i = 2; i < n; i++)  if(n % i)
                {
                    cout << i << '\n';
                   break;
                }
            }
            else cout << "1\n" << x << '\n';
        }
    }
}