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
        if(s.find("hello") != string::npos)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}