#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    bool g = false;
    string s1, s2;
    while(getline(cin, s1))
    {
        getline(cin, s2);
        stringstream ss(s1), ss2(s2);
        vector<int> v;
        int x;
        while(ss >> x)
            v.emplace_back(x);  
        reverse(v.begin(), v.end());
        if(g)   cout << '\n';
        g = true;
        bool f = false;
        while(ss2 >> x)
        {
            if(f)   cout << ' ';
            f = true;
            int p = 1, val = 0;
            for(int c: v) val += c * p, p *= x;
            cout << val;
        }
    }
}