#include <bits/stdc++.h>
using namespace std;

void rotate(string &s) {
    char c = s.back();
    s.pop_back();
    s = c + s;
}
struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
    }
    inline int op(int a, int b) { return a + b; }
    int range_sum(int l, int r) {  
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p) {
        for(t[p += n] = 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

// inversions in a permutation p[1 .. n]
long long inversions(int p[], int n) {
    Segtree st(n);
    long long res = 0;
    for(int i = 0; i < n; i++) {
        st.modify(p[i] - 1);
        res += st.range_sum(p[i], n);
    }
    return res;
}
// inversions in an array
long long inversions(vector<int> &v) {
    map<int, queue<int>> q;
    int n = v.size();
    for(int i = 0; i < n; i++)
        q[v[i]].push(i);
    sort(v.begin(), v.end());
    int p[n] = {};
    for(int i = 0; i < n; i++) {
        p[q[v[i]].front()] = i + 1;
        q[v[i]].pop();
    }
    // return inversions of permutation p
    return inversions(p, n);
}
// min adjacent swaps to make a equal to b
long long inversions(vector<int> &a, vector<int> &b) {
    map<int, queue<int>> q;
    int n = a.size();
    for(int i = 0; i < n; i++)
        q[a[i]].push(i);
    int p[n] = {};
    for(int i = 0; i < n; i++) {
        p[q[b[i]].front()] = i + 1;
        q[b[i]].pop();
    }
    return inversions(p, n);
}
void solve()
{
    int k;  cin >> k;
    map<string, int> mp;
    for(int i = 0; i < k; i++) {
        string a, b; cin >> a >> b;
        a += b[1], a += b[0];
        mp[a]++;
    }
    int n, m;   cin >> n >> m;
    string s[n];
    for(auto &x: s) cin >> x;
    for(int i = 0; i < n; i += 2) {
        string a = "";
        for(int j = 0; j < m; j += 2, a = "") {
            a += s[i][j];
            a += s[i][j + 1];
            a += s[i + 1][j + 1];
            a += s[i + 1][j];
            bool flag = false;
            for(int k = 0; k < 4; k++)
            {
                if(mp[a])
                {
                    mp[a]--;
                    flag = true;
                    break;
                }
                rotate(a);
            }
            if(!flag)   return cout << "No", void();
        }
    }
    cout << "Yes";
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}