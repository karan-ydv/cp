#include <bits/stdc++.h>
using namespace std;
#define int long long

class seg
{
public:
    int n, mx = LLONG_MAX;
    vector<int> tree;
    void create(int temp = 0)
    {
        tree[n] = 0;
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = min(tree[2 * i], tree[(2 * i) + 1]);
        }
    }

    seg(int nn)
    {
        n = nn;
        tree.resize(2 * n, mx);
    }
    int find(int l, int r, int temp = 0)
    {
        int ans = LLONG_MAX;
        l = l + n, r = r + n;
        while (l < r)
        {

            if (l % 2 == 1)
                ans = min(ans, tree[l]), l++;
            if (r % 2)
                ans = min(ans, tree[r - 1]), r--;
            l = l / 2, r = r / 2;
        }
        return ans;
    }
    void change(int x, int val)
    {
        x = x + n;
        tree[x] = val;
        while (x > 1)
        {
            tree[x / 2] = min(tree[x], tree[x ^ 1]);
            x /= 2;
        }
    }
};
int32_t main()
{

    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int n, m;
        cin >> n >> m;

        vector<pair<int, int>> v;

        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            v.push_back({x, y});
        }
        sort(v.begin(), v.end());
        vector<int> ansdp(n + 100, LLONG_MAX);
        seg st(n + 1);
        st.create();
        int j = 0, i = 1;
        while (i <= n)
        {
            while (j < m and v[j].first == i)
            {
                int x = v[j].second;
                int mn = st.find(i - 1, x);
                int val = mn + x;
                val -= v[j].first;
                val++;
                if (ansdp[x] > val)
                {
                    ansdp[x] = val;
                    st.change(x, val);
                }
                j++;
            }
            i++;
        }
        int ans = ansdp[n];
        if (ans == LLONG_MAX)
            cout << -1;
        else
            cout << ans;
        cout << endl;
    }
}