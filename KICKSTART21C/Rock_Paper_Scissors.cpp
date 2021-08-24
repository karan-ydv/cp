#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t, x;	cin >> t >> x;
    vector<pair<int, int>> v(t);
    for(auto &[w, e]: v)    cin >> w >> e;
    vector<pair<int, int>> a(v);
    sort(a.begin(), a.end());
    int r, p, s;
    for(int _ = 1; _ <= t; _ ++)
    {
        auto [w, e] = v[_ - 1];
        cout << "Case #" << _ << ": ";
        r = p = s = 0;
        // int i = find(a.begin(), a.end(), a[_ - 1]) - a.begin();
        // cerr << i << endl;
        // string ans;
        for(int i = 0; i < 60; i++)
        {
            cerr << r << ' ' << s << ' ' << p << endl;
            int mx = -1;
            char c;
            if(r * e + s * w > mx)  mx = r * e + s * w, c = 'R';
            if(s * e + p * w > mx)  mx = s * e + p * w, c = 'S';
            if(p * e + r * w > mx)  mx = p * e + r * w, c = 'P';
            s += c == 'S';
            r += c == 'R';
            p += c == 'P';
            cout << c;
        }
        cout << '\n';
    }

    // cout << "Case #200" << ": ";
    // auto [w, e] = v[t - 1];
    // r = p = s = 0;
    // for(int i = 0; i < 60; i++)
    // {
    //     int mx = -1;
    //     char c;
    //     if(r * e + s * w > mx)  mx = r * e + s * w, c = 'R';
    //     if(s * e + s * w > mx)  mx = r * e + s * w, c = 'S';
    //     if(p * e + s * w > mx)  mx = r * e + s * w, c = 'P';
    //     s += c == 'S';
    //     r += c == 'R';
    //     p += c == 'P';
    //     cout << c;
    // }
}