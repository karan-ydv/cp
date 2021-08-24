#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    reverse(s.begin(), s.end());
    for(char &c:s)
    {
        if(c == '6' or c == '9')
        {
            c ^= '6'^'9';
        }
    }
    cout << s;
}