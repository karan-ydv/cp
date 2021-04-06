#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;	cin >> t;
	while(t--)
	{
		int n, w;	cin >> n >> w;
		int a[n];	for(int &x: a)	cin >> x;
        sort(a, a + n, greater<int>());
        auto possible = [&](int x)
        {
            multiset<int> st;
            for(int i = 0; i < x; i++) {
                st.insert(0);
            }
            int i;
            for(i = 0; i < n; i++)
            {
                auto x = st.upper_bound(w - a[i]);
                if(x == st.begin()) break;
                --x;
                st.insert(*x + a[i]);
                st.erase(x);
            }
            return i == n;
        };
		int beg = 1, end = n, ans = 0;
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(possible(mid))
                ans = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        cout << ans << '\n';
	}
}