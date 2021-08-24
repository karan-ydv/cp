#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v;
    for(int i = 1; i <= 9; i++)
    {
        for(char j = '1'; j <= '9'; j++)
        {
            string s = string(i, j);
            v.push_back(stoi(s));
        }
    }
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = upper_bound(v.begin(), v.end(), n) - v.begin();
        cout << ans << '\n';
    }
}