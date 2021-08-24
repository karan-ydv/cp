#include <bits/stdc++.h>
// #include <sys/resource.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // rlimit R;
    // getrlimit(RLIMIT_STACK, &R);
    // R.rlim_cur = R.rlim_max;
    // setrlimit(RLIMIT_STACK, &R);
    int t;	cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            int x;  cin >> x;
            mp[x]++;
        }
        int x = n;
        x -= mp[0] + mp[1] + mp[-1];
        if(x > 1)
        {
            cout << "0\n";
            continue;
        }
        if(mp[-1])
        {
            if(x > 0)
                cout << "0\n";
            else if(mp[-1] == 1)
                cout << "1\n";
            else if(mp[1])
                cout << "1\n";
            else
                cout << "0\n";
        }
        else
            cout << "1\n";
    }
}