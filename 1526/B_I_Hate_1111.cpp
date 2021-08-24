#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;
        auto fun = [](int n)
        {
            for(int i = 0; i <= min(1110, n); i += 111)
                if((n - i) % 11 == 0) return cout << "YES\n", void();
            cout << "NO\n";
        };
        fun(n);
    }
}