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
        int a[n];
        map<int,int> even, odd;
        for(int i = 0; i < n; i++) {
            cin >> a[i];
            if(i & 1)
                odd[a[i]]++;
            else
                even[a[i]]++;
        }
        sort(a, a+ n);
        for(int i = 0; i < n; i++) {
            if(i & 1)
                odd[a[i]]--;
            else
                even[a[i]]--;
        }
        bool flag = true;
        for(auto [x, f]: even) {
            if(f != 0)
            {
                flag = false;
                break;
            }
        }
        for(auto [x, f]: odd) {
            if(f != 0)
            {
                flag = false;
                break;
            }
        }
        if(flag)    cout << "YES\n";
        else        cout << "NO\n";
    }
}