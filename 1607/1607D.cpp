#include <bits/stdc++.h>
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;  cin >> n;   int a[n];
        for(int &x: a)      cin >> x;
        string s;           cin >> s;

        vector<int> r, b;
        for(int i = 0; i < n; i++)
            (s[i] == 'R' ? r : b).push_back(a[i]);
        
        ranges::sort(b);
        ranges::sort(views::reverse(r));

        bool flag = 1;
        int p = 1, q = n;
        for(int x: b)   flag &= x >= p++;
        for(int x: r)   flag &= x <= q--;

        cout << (flag ? "YES\n" : "NO\n");
    }
}