#include <bits/stdc++.h>
#define int int64_t
using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n, l, r;    cin >> n >> l >> r;
        multiset<int> a, b;
        for(int i = 0;  i < l;  i++) {
            int x;  cin >> x;
            a.insert(x);
        }
        for(int i = 0; i < r; i++) {
            int x;  cin >> x;
            b.insert(x);
        }
        for(auto itr = a.begin(); itr != a.end(); )
        {
            auto itr2 = b.find(*itr);
            auto del = itr++;
            if(itr2 != b.end())
            {
                a.erase(del);
                b.erase(itr2);
            }
        }
        int s1 = a.size(), s2 = b.size();
        if(s1 < s2)
        {
            swap(s1, s2);
            a.swap(b);
        }
        int prev = -1, d = s1 - s2;
        int ans = s1;
        for(int x: a)
        {
            if(d == 0)  break;
            if(x == prev)
            {
                ans -= 1;
                prev = -1;
                d -= 2;
            }
            else prev = x;
        }
        cout << ans << '\n';
    }
}