#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> v;

void calc()
{
    for(int i = 1; ; i++)
    {
        int a = i / 2;
        int b = i - a;
        v.emplace_back((a + 1) * (b + 1) - 1, i);
        if(v.back().first > 1e9)    break;
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    calc();
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        int ans = lower_bound(v.begin(), v.end(), make_pair(n, 0)) -> second;
        cout << ans << '\n' ;
    }
}