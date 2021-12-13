#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n; string x;
    cin >> x >> n;
    string a[n];
    int idx[26];


    for(int i = 0; i < 26; i++)
        idx[x[i] - 'a'] = i;
    
    for(auto &s: a) cin >> s;
    sort(a, a + n, [&](const string &a, const string &b){
        int p = (int) a.length();
        int q = (int) b.length();
        for(int i = 0; i < min(p, q); i++) if(a[i] != b[i])
            return idx[a[i] - 'a'] < idx[b[i] - 'a'];
        return p < q;
    });

    for(auto &s: a) cout << s << '\n';
}