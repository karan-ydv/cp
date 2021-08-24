#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string a[] = {"2B", "3B", "H", "HR"};
    string s[4];
    for(auto &x: s) cin >> x;
    sort(s, s + 4);
    for(int i = 0; i < 4; i++) {
        if(a[i] != s[i])
            return cout << "No", 0;
    }
    cout << "Yes";
}