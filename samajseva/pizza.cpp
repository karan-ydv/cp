#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;
    pair<int, int> p[n];

    for(int i = 0; i < n; i++)
        cin >> p[i].first;
    for(int i = 0; i < n; i++)
        cin >> p[i].second;

    sort(p, p + n, [](pair<int, int> a, pair<int, int> b) {
        return abs(a.first - a.second) > abs(b.first - b.second);
    });

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        int a = p[i].first;
        int b = p[i].second;
        if(a > b)
        {
            if(x > 0)
            {
                ans += a;
                x--;
            }
            else
            {
                ans += b;
                y--;
            }
        }
        else
        {
            if(y > 0)
            {
                ans += b;
                y--;
            }
            else
            {
                ans += a;
                x--;
            }
        }
    }
    cout << ans;
}