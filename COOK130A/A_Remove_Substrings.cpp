#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; int n;  cin >> n >> s;
    if(s[0] != s[n - 1]) return cout << "1", 0;
    for(int i = 1; i < n - 2; i++)
    if(s[i] != s[0] and s[i + 1] != s[0])
        return cout << "2", 0;
    cout << "-1";
}