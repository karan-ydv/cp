#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
int A[N], B[N], C[N], D[N], t[N + N], n;
unordered_map<int, queue<int>> q;

inline int op(int a, int b) { return a + b; }
int range_query(int l, int r) {  // sum of interval [l, r)
    int res = 0;
    for(l += n, r += n; l < r; l >>= 1, r >>= 1) {
        if(l & 1) res = op(res, t[l++]);
        if(r & 1) res = op(res, t[--r]);
    }
    return res;
}
void modify(int p) {  // set 1 at position p
    for(t[p += n] = 1; p > 1; p >>= 1)
        t[p >> 1] = op(t[p], t[p^1]);
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> A[i], A[i] += i, C[i] = A[i];
    
    for(int i = 0; i < n; i++)
        cin >> B[i], B[i] += i, D[i] = B[i];

    sort(C, C + n);
    sort(D, D + n);

    for(int i = 0; i < n; i++)
    if(C[i] != D[i]) return cout << "-1", 0;
    
    for(int i = 0; i < n; i++)
        q[A[i]].push(i);
    
    for(int i = 0; i < n; i++)
    {
        C[q[B[i]].front()] = i;
        q[B[i]].pop();
    }
    
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += range_query(C[i], n);
        modify(C[i]);
    }
    cout << ans;
}