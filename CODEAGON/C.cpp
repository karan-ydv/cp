#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
    }
    inline int op(int a, int b) { return a + b; }
    int range_sum(int l, int r) {  // min on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p) {  // set value at position p
        for(t[p += n] ^= 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

int inversions(string &s, string &v) {
    int n = s.length();
    queue<int> q[10];
    for(int i = 0; i < n; i++)
        q[s[i] - '0'].push(i);
 
    int a[n] = {};
    s.swap(v);
    for(int i = 0; i < n; i++) 
    {
        a[q[s[i] - '0'].front()] = i + 1;
        q[s[i] - '0'].pop();
    }
 
    Segtree st(n);
    long long ans = 0;
    for(int i = 0; i < n; i++) {
        st.modify(a[i] - 1);
        (ans += st.range_sum(a[i], n)) %= mod;
    }

    return ans;
}

int solve(vector<int> &v) {
    string str = "";

    int a[10] = {};
    for(int x: v)   a[x]++, str += '0' + x;

    int n = v.size();
    vector<string> s;
    while(n)
    {
        string x = "";
        for(int i = 9; i >= 0; i--) if(a[i])
        {
            a[i]--, n--;
            x += '0' + i;
        }
        cerr << x << '\n';
        s.emplace_back(x);
    }

    sort(s.begin(), s.end(), [](string x, string y){
        return x + y > y + x;
    });
    
    string str2 = "";
    for(auto &x: s) str2 += x;
    cerr << str2 << '\n';
    return inversions(str, str2);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<int> v(n);
    for(int &x: v)  cin >> x;
    // vector<int> v = {7, 1, 3, 0, 0, 0, 1, 7, 7, 4, 0, 7, 0, 4, 6, 0, 6, 2, 8, 0, 0, 0, 2, 0, 0, 2, 2, 2, 6, 0, 4, 5, 6, 0, 6, 4, 5, 0, 0, 0, 0, 4, 0, 8, 0, 0, 0, 0, 2};
    cout << solve(v);
}