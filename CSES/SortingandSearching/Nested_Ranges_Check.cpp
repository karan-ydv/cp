#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 69;
array<int, 3> a[N];
bool ans1[N], ans2[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i][1] >> a[i][0];
        a[i][2] = i;
    }
    sort(a, a + n);


    for(int i = 1; i < n; i++)
    {
        if(a[i - 1][0] < a[i][1])
            ans2[a[i - 1][2]] = 1;
        else if(a[i - 1][0] >= a[i][0])
        {
            ans1[a[i][2]] = 1;
            ans2[a[i - 1][2]] = 1;
        }
        else
        {
            
        }
    }

    for(int i = 0; i < n; i++)
        cout << ans1[i] << ' '; cout << '\n';
    for(int i = 0; i < n; i++)
        cout << ans2[i] << ' ';
}