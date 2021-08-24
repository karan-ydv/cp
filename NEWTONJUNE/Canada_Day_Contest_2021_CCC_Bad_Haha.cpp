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
        string s; int k;
        cin >> s >> k;
        int n = s.length();
        if(k >= n)
        {
            sort(s.begin(), s.end());
            cout << s << '\n';
            continue;
        }
        int i = min_element(s.begin(), s.begin() + k) - s.begin();
    }
}