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
        int n; string s, p;
        cin >> n >> s >> p;
        if(s == p) {
            cout << "YES\n"; continue;
        }
        bool f1 = false, f2 = false;
        bool f3 = false, f4 = false;
        for(int i = 0; i < n; i++) {
            f1 |= (s[i] == '0' and p[i] == '0');
            f2 |= (s[i] == '1' and p[i] == '1');
            f3 |= (s[i] == '1' and p[i] == '0');
            f4 |= (s[i] == '0' and p[i] == '1');
        }
        cerr << f1 << f2 << f3 << f4;
        if((f1 and f2) or (f3 and f4) or (f1 and f4) or (f2 and f3)) {
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
}