#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for(int i = 0; i < 26; i++) {
        int x;  cin >> x;
        cout << char('a' + x - 1);
    }
}