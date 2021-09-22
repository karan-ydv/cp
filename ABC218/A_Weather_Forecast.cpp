#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;      cin >> n;
    string s;   cin >> s;
    if(s[n - 1] == 'x')
        cout << "No";
    else
        cout << "Yes";

}