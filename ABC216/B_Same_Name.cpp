#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    cin.get();
    set<string> set;
    for(int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        if(set.count(s))
            return cout << "Yes", 0;
        set.insert(s);
    }
    cout << "No";
}