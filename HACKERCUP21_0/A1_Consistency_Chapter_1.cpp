/* compile with 
g++ A1_Consistency_Chapter_1.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;


const string V = "AEIOU";
bool vowel(char c) {
    return V.find(c) != string::npos;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        string s;   cin >> s;
        int ans = 1e9;
        for(char c = 'A'; c <= 'Z'; c++)
        {
            int cnt = 0;
            for(char x: s) if(x != c)
                cnt += 1 + (vowel(x) == vowel(c));
            ans = min(ans, cnt);
        }
        cout << ans << '\n';
    }
}