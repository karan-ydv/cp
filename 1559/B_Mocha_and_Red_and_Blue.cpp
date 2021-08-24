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
        string s; int n;
        cin >> n >> s;
        s = "!" + s + "!";
        for(int i = 1; i <= n; i++) if(s[i] == '?') {
            int j = i, R, B;
            while(s[j] == '?') j++;
            if((j - i) & 1)
            {
                R = (s[i - 1] == 'R') + (s[j] == 'R');
                B = (s[i - 1] == 'B') + (s[j] == 'B');
            }
            else
            {
                R = (s[i - 1] == 'R') + (s[j] == 'B');
                B = (s[i - 1] == 'B') + (s[j] == 'R');
            }
            char ch = R < B ? 'R' : 'B';
            for(int k = i; k < j; k++, ch ^= 'R' ^ 'B')
                s[k] = ch;
            i = j;
        }
        cout << s.substr(1, n) << '\n';
    }
}