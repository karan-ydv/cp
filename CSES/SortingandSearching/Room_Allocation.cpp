#include <bits/stdc++.h>
#define int int64_t
using namespace std;

const int N = 2e5+69;
array<int, 3> a[N];
int ans[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    
    int k = 0;
    for(int i = 1; i <= n; i++)
    {
        auto &[y, x, z] = a[i];
        int beg = 1, end = i - 1, prev = -1;
        while(beg <= end)
        {
            int mid = beg + end >> 1;
            if(a[mid][0] < x)
                prev = mid, end = mid - 1;
            else
                beg = mid + 1;
        }
        if(prev != -1)
            ans[z] = ans[prev];
        else
            ans[z] = ++k;
    }
    cout << k << '\n';
    for(int i = 1; i <= n; i++)
        cout << ans[i] << ' ';
}