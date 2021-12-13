#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+4;
int prefEven[N], prefOdd[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int q; string s;
        cin >> s >> q;
        int n = (int) s.length();
        s = "!" + s;
        for(int i = 1; i <= n; i++) {
            prefEven[i] = prefEven[i - 1];
            prefOdd[i] = prefOdd[i - 1];
            if(s[i] == '[' or s[i] == ']')
            {
                prefOdd[i] += i & 1;
                prefEven[i] += !(i & 1);
            }
        }
        while(q--)
        {
            int l, r; cin >> l >> r; --l;
            int odd = prefOdd[r] - prefOdd[l];
            int even = prefEven[r] - prefEven[l];
            cout << abs(even - odd) << '\n';
        }
    }
}