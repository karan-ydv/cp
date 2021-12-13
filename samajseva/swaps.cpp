#include <bits/stdc++.h>
using namespace std;

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
    int mid = beg + end >> 1;
    inv += inversions(a, beg, mid);
    inv += inversions(a, mid, end);
    inv += merge(a, beg, mid, end);
    return inv;
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

long long merge(const deque<int>& a, const deque<int>& b) {
    int i = 0, j = 0;
    long long inv = 0;
    while(i < a.size() and j < b.size())
        if(a[i] <= b[j]) i++;
        else inv += a.size() - i, j++;
    return inv;
}

long long solve(int a[], int n) {
    map<int, deque<int>> q;
    for(int i = 0; i < n; i++)
        q[a[i]].push_back(i);

    vector<deque<int>> v;
    for(auto &[x, vec]: q)
        v.emplace_back(vec);
    
    sort(v.begin(), v.end(), [](const deque<int>& a, const deque<int>& b){
        return merge(a, b) < merge(b, a);
    });

    int p[n], i = 0;
    for(auto &q: v) for(int x: q) p[i++] = x;
    return inversions(p, 0, n);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    int a[n];
    for(int &x: a)  cin >> x;
    cout << solve(a, n);
}