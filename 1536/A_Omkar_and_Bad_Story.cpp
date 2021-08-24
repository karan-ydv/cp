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
        vector<int> a(n);
        for(int &x: a)  cin >> x;
        sort(a.begin(), a.end());
        set<int> b(a.begin(), a.end());
        bool possible = true, flag = true;
        while(flag)
        {
            flag = false;
            for(int i = 0; i < n; i++)
            {
                for(int j = i + 1; j < n; j++)
                if(!b.count(abs(a[i] - a[j])))
                {
                    if(b.size() >= 300)
                    {
                        possible = false;
                        goto end;
                    }
                    flag = true;
                    b.insert(abs(a[i] - a[j]));
                }
            }
            a = vector<int>();
            for(int x: b)   a.emplace_back(x);
            n = a.size();
        }
        end:
        if(possible)
        {
            cout << "yes\n";
            cout << b.size() << '\n';
            for(int x: b)   cout << x << ' ';
            cout << "\n";
        }
        else
            cout << "no\n";
    }
}