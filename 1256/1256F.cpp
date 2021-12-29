#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int fastexp(int a, int n){
    int p = 1;
    for(; n; n >>= 1, (a *= a) %= mod)
        if(n & 1)	(p *= a) %= mod;
    return p;
}

long long merge(int a[], int beg, int mid, int end)
{
    int i = beg, j = mid;
    long long inv = 0;
    while(i < mid and j < end)
        if(a[i] < a[j]) i++;
        else    inv += mid - i, j++;
    std::inplace_merge(a + beg, a + mid, a + end);
    return inv;
}

// sort arr[beg:end) and return no. of inversions
long long inversions(int a[], int beg, int end)
{
    long long inv = 0;
    if(end - beg < 2)   return 0;
    if(end - beg == 2)
    {
        if(a[beg] < a[beg + 1]) return 0;
        else    return swap(a[beg], a[beg + 1]), 1;
    }
    int mid = (beg + end) >> 1;
    inv += inversions(a, beg, mid);
    inv += inversions(a, mid, end);
    inv += merge(a, beg, mid, end);
    return inv;
}

// inversions in an array
long long inversions(string &v) {
    map<char, queue<int>> q;
    int n = (int) v.size();
    for(int i = 0; i < n; i++)
        q[v[i]].push(i);
    sort(v.begin(), v.end());
    int p[n] = {};
    for(int i = 0; i < n; i++) {
        p[q[v[i]].front()] = i + 1;
        q[v[i]].pop();
    }
    return inversions(p, 0, n);
}


bool solve()
{
    int n;	cin >> n;
    string s, t;   cin >> s >> t;
    if(s == t)  return true;
    int f[26]{};
    for(char c: s) f[c - 'a']++;
    bool flag = any_of(f, f + 26, [](int x){return x > 1;});
    for(char c: t) f[c - 'a']--;
    for(int x: f)
        if(x != 0) return false;
    return flag or (inversions(s) & 1) == (inversions(t) & 1);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        solve() ? cout << "YES\n" : cout << "NO\n";
    }
}