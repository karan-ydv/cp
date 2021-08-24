#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    inline int op(int a, int b) { return a + b; }
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
    }
    int range_op(int l, int r) {  // op on interval [l, r)
        int res = 0;    // neutral value
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p, int value) {  // set value at position p
        for(t[p += n] = value; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

long long inversions(string& s)
{
    int n = s.length();
    queue<int> q[26];
    for(int i = 0; i < n; i++)
        q[s[i] - 'a'].push(i);
    int a[n];
    sort(s.begin(), s.end());
    for(int i = 0; i < n; i++) {
        a[q[s[i] - 'a'].front()] = i;
        q[s[i] - 'a'].pop();
    }
    long long inv = 0;
    Segtree st(n);
    for(int i = 0; i < n; i++)
    {
        inv += st.range_op(a[i], n);
        st.modify(a[i], 1);
    }
    return inv;
}

bool solve()
{
    string s1, s2;
    int n;	cin >> n >> s1 >> s2;
    vector<int> v1(26), v2(26);
    for(char c: s1) v1[c - 'a']++;
    for(char c: s2) v2[c - 'a']++;
    if(v1 == v2)
    {
        for(int x: v1)  if(x > 1)   return true;
        for(int x: v2)  if(x > 1)   return true;
        return (inversions(s1) & 1) == (inversions(s2) & 1);
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        if(solve())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}