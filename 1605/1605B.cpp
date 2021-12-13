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
        int n;	cin >> n;
        string s;   cin >> s;
        int zero = count(s.begin(), s.end(), '0');
        vector<int> ans;
        for(int i = 0; i < zero; i++)
            if(s[i] == '1') ans.emplace_back(i + 1);
        for(int i = zero; i < n; i++)
            if(s[i] == '0') ans.emplace_back(i + 1);
        if(ans.empty())
            cout << "0\n";
        else
        {
            cout << "1\n" << ans.size() << ' ';
            for(int x: ans) cout << x << ' ';
            cout << '\n';
        }
    }
}