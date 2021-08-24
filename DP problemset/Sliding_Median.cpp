#include <bits/stdc++.h>
using namespace std;

struct kthone
{
    int N;
    vector<int> t;
    kthone(int n)
    {
        N = 1;
        while (N < n)
            N <<= 1;
        t.resize(N << 1);
    }
    void modify(int p, int v)
    { // set value at position p
        p += N;
        for (t[p] += v; p > 1; p >>= 1)
            t[p >> 1] = t[p] + t[p ^ 1];
    }
    int Kth_One(int k)
    {
        int i = 0, s = N >> 1;
        for (int p = 2; p < 2 * N; p <<= 1, s >>= 1)
        {
            if (k < t[p])
                continue;
            k -= t[p++];
            i += s;
        }
        return i;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int &x : a)
        cin >> x;

    /* co-ordinate compression */
    vector<int> v(a);
    sort(v.begin(), v.end());
    v.resize(unique(v.begin(), v.end()) - v.begin());
    unordered_map<int, int> idx;
    for (int i = 0; i < v.size(); i++)
        idx[v[i]] = i;

    kthone obj(v.size());
    for (int i = 0; i < k; i++)
        obj.modify(idx[a[i]], 1);

    int m = (k - 1) / 2;

    cout << v[obj.Kth_One(m)] << ' ';
    for (int i = k; i < n; i++)
    {
        obj.modify(idx[a[i]], 1);
        obj.modify(idx[a[i - k]], -1);
        cout << v[obj.Kth_One(m)] << ' ';
    }
}