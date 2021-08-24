#include <bits/stdc++.h>
using namespace std;

struct Segtree {
    int n;
    vector<int> t;
    Segtree(int n) {
        this -> n = n;
        t.resize(n << 1);
        for(int i = 0; i < n; i++)
            cin >> t[n + i];
    }
    inline int op(int a, int b) { return a + b; }
    int range_sum(int l, int r) {  // query on interval [l, r)
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res = op(res, t[l++]);
            if(r & 1) res = op(res, t[--r]);
        }
        return res;
    }
    void modify(int p) {  // set value at position p
        for(t[p += n] = 1; p > 1; p >>= 1)
            t[p >> 1] = op(t[p], t[p^1]);
    }
};

const int N = 2e5+69;
int A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s; cin >> s;
    int n = s.length();
    deque<int> q[26];
    for(int i= 0; i < n; i++)
        q[s[i] - 'a'].push_back(i);
    
    int cnt = 0;
    for(int i = 0; i < 26; i++)
        cnt += q[i].size() & 1;
    
    if(cnt > 1) return cout << "-1", 0;
    
    for(int i = 0, idx = 0; i < n; i++)
    {
        int j = s[i] - 'a';
        if(q[j].size())
        {
            if(q[j].size() == 1)
            {
                A[q[j].front()] = n / 2;
                q[j].pop_back();
                continue;
            }
            A[q[j].front()] = idx++;
            A[q[j].back()] = n - idx;
            q[j].pop_front();
            q[j].pop_back();
        }
    }
    
    Segtree st(n);
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += st.range_sum(A[i], n);
        st.modify(A[i]);
    }

    cout << ans;
}