#include <bits/stdc++.h>
using namespace std;

int f[26][2], g[26][2], a, b;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s >> t;
    for(char c: s) {
        if(islower(c))
            f[c - 'a'][0]++;
        else
            f[c - 'A'][1]++;
    }
    for(char c: t) {
        if(islower(c))
            g[c - 'a'][0]++;
        else
            g[c - 'A'][1]++;
    }
    for(int i = 0; i < 26; i++) for(int j:{0,1}) {
        int x = min(f[i][j], g[i][j]);
        a += x;
        f[i][j] -= x;
        g[i][j] -= x;
    }
    for(int i = 0; i < 26; i++) for(int j:{0,1}) {
        int x = min(f[i][j], g[i][j^1]);
        b += x;
        f[i][j] -= x;
        g[i][j^1] -= x;
    }
    cout << a << ' ' << b;
}