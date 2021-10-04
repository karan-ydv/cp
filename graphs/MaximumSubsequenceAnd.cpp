#include <bits/stdc++.h>
using namespace std;

#define int int64_t
const int mod = 1e9+7;
int modExp(int a, int n) {
    int res = 1;
    for(; n; (a *= a) %= mod, n >>= 1)
        if(n & 1)	(res *= a) %= mod;
    return res;
}
int fact(int k) {
    int f = 1;
    for(int i = 2; i <= k; i++)
        (f *= i) %= mod;
    return f;
}
int ncr(int n, int r) {
    int res = fact(n) * modExp(fact(r), mod - 2) % mod;
    (res *= modExp(fact(n - r), mod - 2)) %= mod;
    return res;
}
#undef int
int sortByBit(vector<int> &arr, int bit)
{
    int l = 0, r = arr.size() - 1;
    while(l <= r)
    {
        if(arr[l] & bit)        l++;
        else if(arr[r] & bit)	swap(arr[l++], arr[r--]);
        else r--;
    }
    return l;
}
vector<int> maximalANDSubsequences(vector<int> &arr, int k) {
    for(int b = 1 << 30; b and arr.size() > k; b >>= 1)
    {
        int c = sortByBit(arr, b);
        cerr << b << ' ' << c << '\n';
        for(int x: arr) cerr << x << ' '; cerr << '\n';
       	if(c >= k)
        {
            while(!(arr.back() & b))
                arr.pop_back();
        }
    }
    int ans = arr[0];
    for(int i = 0; i < k; i++)
        ans &= arr[i];
    return {ans, (int)ncr(arr.size(), k)};
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;  cin >> t;
    while(t--)
    {
        int n, k;   cin >> n >> k;
        vector<int> arr(n);
        for(int &x: arr)    cin >> x;
        for(int x: maximalANDSubsequences(arr, k))
            cout << x << ' '; cout << '\n';
    }
}