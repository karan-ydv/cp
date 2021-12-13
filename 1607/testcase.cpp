#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("input.txt", "w", stdout);
    cout << "1\n\n2000 2000\n";
    string s1 = string(1999, 'R') + "D";
    string s2 = "D" + string(1999, 'L');
    for(int i = 0; i < 1000; i++)
        cout << s1 << '\n' << s2 << '\n';
}