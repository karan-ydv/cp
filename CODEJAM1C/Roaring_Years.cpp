#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool roaring(string s)
{
    for(int i = 1; i < s.size(); i++)
    {
        int p = 0, c = 0;
        for(int j = 0; j < i; j++)
            p = p * 10 + (s[j] - '0');
        // cerr << p << '\n';
        if(s[i] == '0') continue;
        int j = i;
        while(j < s.size())
        {
            c = c * 10 + (s[j] - '0');
            j++;
            if(j == s.size() and c == p + 1)
                return true;
            if(c > p)
            {
                if(c == p + 1)
                {
                    p = c;
                    c = 0;
                    if(s[j] == '0') break;
                }
                else            break;
            }
        }
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // cerr << roaring("2122");
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        int n;  cin >> n;
        n += 1;
        string s;   cin >> s;
        for(int i = 1; i < s.length(); i++)
        {

        }
        cout << "Case #" << _ << ": " << n << '\n';
    }
}