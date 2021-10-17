#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct object {
    int x1, y1, x2, y2;
};

istream& operator>> (istream& stream,  object& o) {
    stream >> o.x1 >> o.y1 >> o.x2 >> o.y2;
    return stream;
}

int fun(vector<pair<int, int>> v)
{
    sort(v.begin(), v.end());
    return v[(v.size() - 1) / 2].first;
}
int fun(vector<int> v)
{
    sort(v.begin(), v.end());
    return v[(v.size() - 1) / 2];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    for(int _ = 1; _ <= t; _ ++) {
        cout << "Case #" << _ << ": ";
        int n;  cin >> n;
        object o[n];
        for(auto &x: o) cin >> x;

        // vector<pair<int, int>> vx, vy;
        vector<int> vx, vy;
        for(auto &x: o)
        {
            vx.emplace_back(x.x1);
            vx.emplace_back(x.x2);
            vy.emplace_back(x.y1);
            vy.emplace_back(x.y2);
            // vx.emplace_back(min(x.x1, x.x2), max(x.x1, x.x2));
            // vy.emplace_back(min(x.y1, x.y2), max(x.y1, x.y2));
        }
        
        cout << fun(vx) << ' ' << fun(vy) << '\n';
    }
}