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
        int x = count(s.begin(), s.end(), 'B');
        x == n / 2 and n % 2 == 0? cout << "YES\n" : cout << "NO\n";
    }
}