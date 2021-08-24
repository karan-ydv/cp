#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int mod = 1e9+7;
int value(string s)
{
    int ans = 0;
    for(char c: s)
    {
        ans = ans * 10 + (c - '0');
        ans %= mod;
    }
    return ans;
}
int fastexp(int a, int n){
    int p = 1;
    while(n)
    {
        if(n & 1)	p = p * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return p;
}
int fun(int x, int l, int j)
{
    int a = x * (fastexp(10, l) + mod - 1) % mod;
    (a *= fastexp(9, mod - 2)) %= mod;
    (a *= fastexp(10, j)) %= mod;
    return a;
}
int maximumnumber(string A, vector<int> F)
{
    int n = A.length();
    int v = value(A);
    int ans = v;
    for(int i = 0; i < n; )
    {
        int j;
        for(j = i + 1; j < n; j++)
            if(A[j] != A[i])    break;
        
        int x = fun(A[i] - '0', j - i, n - j);
        int y = fun(F[A[i] - '1'], j - i, n - j);
        ans = max(ans, (v + y - x + mod) % mod);
        i = j;
    }
    return ans;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    vector<int> f;
    cin >> s;
    for(int i = 0; i < 9; i++)
    {
        int x; cin >> x;
        f.emplace_back(x);
    }
    cout << maximumnumber(s, f);
}