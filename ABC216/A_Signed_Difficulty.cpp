#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string x;   cin >> x;
    char y = x.back();
    x.pop_back();
    x.pop_back();
    if(y < '3')
        cout << x << '-';
    else if(y < '7')
        cout << x;
    else
        cout << x << '+';
}