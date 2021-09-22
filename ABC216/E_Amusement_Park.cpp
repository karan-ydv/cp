#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int natural(int n) {
    return n * (n + 1) / 2;
}
int natural(int i, int j) {
    return natural(j) - natural(i);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    map<int, int> mp;
    for(int i = 0; i < n; i++)
    {
        int x;  cin >> x;
        mp[x]++;
    }
    int ans = 0;
    while(k and mp.size() > 1)
    {
        auto i1 = --mp.end();
        auto i2 = i1; --i2;
        auto [a, f1] = *i1;
        auto [b, f2] = *i2;
        cerr << a << ' ' << f1 << '\n';
        cerr << b << ' ' << f2 << '\n';
        int rides = f1 * (a - b);
        if(k < rides)   break;
        else
        {
            ans += f1 * natural(b, a);
            k -= rides;
            cerr << mp.size() << ' ';
            mp.erase(i1);
            cerr << mp.size() << '\n';
            mp[b] += f1;
        }
        cerr << '\n';
    }
    if(k)
    {
        auto [a, f] = *mp.rbegin();
        if(k < a * f)
        {
            int i = k / f;
            ans += f * natural(a - i, a);
            ans += (a - i) * (k - i * f);
        }
        else
            ans += f * natural(a);
    }
    cout << ans;
}