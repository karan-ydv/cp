#include <bits/stdc++.h>
using namespace std;

string t;
string fun(int idx, string s)
{
    // cerr << idx << ' ' << s << '\n';
    if(s.length() == 1)
    {
        if(s[0] <= t[idx])
            return s;
        return "-1";
    }

    if(s.back() > t[idx]) return "-1";
    bool tried = false;
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] < t[idx])
        {
            char ch = s[i];
            s.erase(s.begin() + i);
            s = ch + s;
            return s;
        }
        if(s[i] == t[idx] and !tried)
        {
            string v = s;
            v.erase(v.begin() + i);
            string w = fun(idx + 1, v);
            if(w != "-1")
                return t[idx] + w;
            tried = true;
        }
    }
    return "-1";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s >> t;
    sort(s.rbegin(), s.rend());
    if(s.length() < t.length() or s <= t)
        return cout << s, 0;
    cout << fun(0, s);
}