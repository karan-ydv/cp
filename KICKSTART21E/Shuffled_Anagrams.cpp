#include <bits/stdc++.h>
#define int int64_t
using namespace std;

bool check(string &s1, string &s2) {
    for(int i = 0; i < s1.length(); i++)
        if(s1[i] == s2[i])  return false;
    return true;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        string s;   cin >> s;
        if(s.length() > 10)
            exit(0);
        string a = s;
        sort(a.begin(), a.end());
        do
        {
            if(check(s, a)) break;
        } while (next_permutation(a.begin(), a.end()));
        
        if(check(s, a))
            cout << a << '\n';
        else
            cout << "IMPOSSIBLE\n";
    }
}