#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand (time(NULL));
    int n;  cin >> n;
    int a[n];   for(int &x: a)  cin >> x;
    int q;  cin >> q;
    int ans[q];
    tuple<int, int, int> query[q];
    for(int i = 0; i < q; i++)
    {
        auto &[a, b, c] = query[i];
        cin >> a >> b;
        a--, b--;
        c = i;
    }
    map<int, bool> mp;
    int count = 0;
    sort(query, query + q);
    int L = 0, R = -1;
    for(auto [l, r, i]: query)
    {
        while(L < l)
        {
            count -= mp[a[l]];
            mp[a[l]] ^= 1;
            count += mp[a[l]];
            l++;
        }
        while(R < r)
        {
            ++R;
            count -= mp[a[R]];
            mp[a[R]] ^= 1;
            count += mp[a[R]];
        }
    }
}