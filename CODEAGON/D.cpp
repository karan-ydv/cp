#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int solve(vector<int> &a, vector<int>& b) {
    typedef pair<int, int> pii;
    int n = a.size();
    int ans = accumulate(a.begin(), a.end(), 0ll) * n % mod;

    pair<int, int> p[n];
    for(int i = 0; i < n; i++)
        p[i] = {a[i], b[i]};
    
    sort(p, p + n, [](pii x, pii y){
        return x.first - x.second < y.first - y.second;
    });

    int pref[n], suff[n];
    pref[0] = p[0].second;
    suff[n - 1] = p[n - 1].first;

    for(int i = 1; i < n; i++)
        pref[i] = (pref[i - 1] + p[i].second) % mod;
    for(int i = n - 2; i >= 0; i--)
        suff[i] = (suff[i + 1] + p[i].first) % mod;


    for(int i = 0; i < n; i++) {
        int d = b[i] - a[i];
        int beg = 0, end = n - 1, x = n;
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(p[mid].first + d < p[mid].second)
                beg = mid + 1;
            else
                x = mid, end = mid - 1;
        }
        if(x < n)   (ans += suff[x]) %= mod;
        if(x > 0)   (ans += pref[x - 1]) %= mod;
        if(d < 0)   d += mod;
        (ans += (n - x) * d % mod) %= mod;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> a(n), b(n);
    for(int &x: a)  cin >> x;
    for(int &x: b)  cin >> x;
    cout << solve(a, b);
}