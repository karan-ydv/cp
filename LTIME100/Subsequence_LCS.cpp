#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int N;
struct SegTree
{
    vector<int> t;
    SegTree(vector<int> &v)
    {
        N = 1;
        int n = v.size();
        while(N < n)	N <<= 1;
        t.resize(N << 1, 0);
        for(int i = N; i < N + n; i++)	t[i] = v[i - N];
        for(int i = N - 1; i > 0; i--)
        t[i] = max(t[i << 1], t[i << 1|1]);
    }
    // returns idx >= l of first element >= x, 0 based indexing
    int first_above(int x, int l, int p = 1, int s = N) {
        if(t[p] < x or s <= l)	return -1;
        if((p << 1) >= 2 * N)
            return (t[p] >= x) - 1;
        int i = first_above(x, l, p << 1, s >> 1);
        if(i != -1)	return i;
        i = first_above(x, l - (s >> 1), p << 1 | 1, s >> 1);
        if(i == -1)	return -1;
        return (s >> 1) + i;
    }
};

void lis(vector<int> &v, vector<int> &nxt, vector<int> &inc)
{
    int n = v.size();
    nxt.resize(n + 1);
    inc.resize(n + 1);
    SegTree st(v);
    for(int i = n - 1; i >= 0; i--)
    {
        int x = st.first_above(v[i], i + 1);
        if(x == -1)
            nxt[v[i]] = n;
        else
            nxt[v[i]] = v[x];
        inc[v[i]] = 1 + inc[nxt[v[i]]];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int a[n];
        for(int &x: a)  cin >> x;
        vector<int> v(n);
        iota(v.begin(), v.end(), 0);
        sort(v.begin(), v.end(), [&](int i, int j){
            return a[i] < a[j] || (a[i] == a[j] and i < j);
        });
        
        vector<int> nxt, inc;
        lis(v, nxt, inc);
        
        sort(v.begin(), v.end(), [&](int i, int j){
            return a[i] > a[j] || (a[i] == a[j] and i < j);
        });

        vector<int> nxt2, dec;
        lis(v, nxt2, dec);
        for(int x: v) cerr << x << ' '; cerr << '\n';
        for(int x: inc) cerr << x << ' '; cerr << endl;
        for(int x: nxt) cerr << x << ' '; cerr << endl;
        for(int x: dec) cerr << x << ' '; cerr << endl;
        for(int x: nxt2) cerr << x << ' '; cerr << endl;
        cerr << '\n';
    }
}