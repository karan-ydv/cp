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
        int n;	cin >> n;
        string s[n];
        for(auto &x: s)
            cin >> x;
        string ans = "asdfd";
        for(int i = 0; i <= 100; i++) {
            bitset<100> b(i);
            string a = b.to_string().substr(100 - n, n);
            int j;
            for(j = 0; j < n; j++)
                if(s[j] == a) break;
            if(j == n)
            {
                ans = a;
                break;
            }
        }
        cout << ans << '\n';
    }
}