#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s[3];
    for(auto &x: s) cin >> x;
    string t;   cin >> t;
    for(char c: t)
        cout << s[c - '1'];
}