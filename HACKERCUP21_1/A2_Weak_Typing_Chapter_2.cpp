/* compile with 
g++ A2_Weak_Typing_Chapter_2.cpp -O2 -std=c++17 -Wl,--stack=268435456
*/
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

vector<int> solve(string s) {
    int ans = 0, sum = 0, cnt = 0;
    char prev = '!';
    vector<int> v;
    for(char c: s)
    {
        if(c != 'F')
        {
            ans += c != prev;
            prev = c;
        }
        v.emplace_back(max(0ll, ans -1));
    }
    return v;
}

const int mod = 1e9+7;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n; string s;
        cin >> n >> s;

        vector<int> v = solve(s);
        reverse(s.begin(), s.end());
        vector<int> v2 = solve(s);
        reverse(v2.begin(), v2.end());
        
        int sum = accumulate(v.begin(), v.end(), 0ll) % mod;
        int cnt = v.end() - find(v.begin(), v.end(), 1);
        queue<int> q;
        for(int i = n - cnt, j; i < n; ) {
            for(j = i; j < n; j++)
                if(v[j] != v[i]) break;
            q.push(j - i);
            i = j;
        }
        int ans = sum;
        for(int i = 1; sum and i < n - 1; i++) {
            if(v2[i] != v2[i - 1])
            {
                (sum += mod - cnt) %= mod;
                cnt -= q.front();
                q.pop();
            }
            (ans += sum) %= mod;
        }
        cout << ans << '\n';
    }
}