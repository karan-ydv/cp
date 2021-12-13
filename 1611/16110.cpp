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
        if(n & 1)
        {
            string s = to_string(n);
            bool f = false;
            for(char c: s) f |= ((c - '0') % 2 == 0);
            if(!f)
                cout << "-1\n";
            else
            {
                if((s[0] - '0') & 1)
                    cout << "2\n";
                else
                    cout << "1\n";
            }
        }
        else
        {
            cout << "0\n";
        }
    }
}