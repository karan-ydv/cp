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
        string s;   cin >> s;
        int n = s.length();
        sort(s.begin(), s.end());
        int a = 0, b = 0;
        for(int i = 0; i + 1 < n; )
        {
            (a *= 10) += s[i++] - '0';
            (b *= 10) += s[i++] - '0';
        }
        if(n & 1)
            (a *= 10) += s.back() - '0';
        cout << a + b << '\n';
    }
}