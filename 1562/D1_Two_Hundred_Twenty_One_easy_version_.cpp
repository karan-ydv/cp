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
        int n, q;   cin >> n >> q;
        string s;   cin >> s;
        int pref1[n + 1] = {};
        int pref2[n + 1] = {};
        s = "!" + s;
        for(int i = 1; i <= n; i++) {
            int a = s[i] == '+' ? 1 : -1;
            pref1[i] = pref1[i - 1];
            pref2[i] = pref2[i - 1];
            if(i & 1)
            {
                pref1[i] += a;
                pref2[i] -= a;
            }
            else
            {
                pref1[i] -= a;
                pref2[i] += a;
            }
        }
        for(int x: pref1)   
            cerr << x << ' '; cerr << '\n';
        for(int x: pref2)   
            cerr << x << ' '; cerr << '\n';
        cerr << '\n';
        while(q--)
        {
            int l, r;   cin >> l >> r;
            // cerr << l  << ' ' << r << " : " << pref1[l - 1] << ' ' << pref1[r] << '\n';
            if(l & 1)
                cout << abs(pref1[r] - pref1[l - 1]) << '\n';
            else
                cout << abs(pref2[r] - pref2[l - 1]) << '\n';
        }
    }
}