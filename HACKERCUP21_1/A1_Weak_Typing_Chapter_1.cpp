/* compile with 
g++ A1_Weak_Typing_Chapter_1.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n; string s;   cin >> n >> s;
        int ans = 0;
        char prev = '!';
        for(char c: s) if(c != 'F')
        {
            ans += c != prev;
            prev = c;
        }
        if(ans) ans -= 1;
        cout << ans << '\n';
    }
}