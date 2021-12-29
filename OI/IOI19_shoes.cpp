#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+69;
queue<int> mp[N];
int p[N], t[N + N];

struct Segtree {
    int n;
    Segtree(int n) : n(n) {
        memset(t, 0, 2 * n * sizeof(int));
    }
    int range_sum(int l, int r) {  
        int res = 0;
        for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
            if(l & 1) res += t[l++];
            if(r & 1) res += t[--r];
        }
        return res;
    }
    void modify(int p) {
        for(t[p += n] = 1; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p^1];
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


long long count_swaps(vector<int> a) {
    int n = (int) a.size();
    int m = n / 2;
    for(int i = 0, c = 1; i < n; i++)
    {
        if(mp[m + a[i]].empty())
        {
            if(a[i] > 0)
            {
                mp[m - a[i]].push(c);
                p[i] = c + 1;
            }
            else
            {
                p[i] = c;
                mp[m - a[i]].push(c + 1);
            }
            c += 2;
        }
        else
        {
            p[i] = mp[m + a[i]].front();
            mp[m + a[i]].pop();
        }
    }
    return inversions(p, n);
}

// int main()
// {
//     int n;  cin >> n;
//     vector<int> v(n + n);
//     for(int &x: v)  cin >> x;
//     cout << count_swaps(v);
// }