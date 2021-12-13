#include <bits/stdc++.h>
#define int int64_t
using namespace std;

typedef tuple<int, int, int> circle;

int intersect(circle &a, circle& b)
{
    auto [r1, x1, y1] = a;
    auto [r2, x2, y2] = b;
    double d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
    if((double) r1 >= d + (double) r2)   return -1;
    if((double) (r1 + r2) <= d)   return 1;
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    circle a[n];
    for(auto &[r, x, y]: a)
        cin >> x >> y >> r;
    
    sort(a, a + n, greater<circle>());

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int c = 1;
        int p = i;
        for(int j = 0; j < n; j++) if(i != j)
        {
            int x = intersect(a[i], a[j]);
            if(x == 0)
            {
                c = 0;
                break;
            }
            if(x == 1)  continue;
            int y = intersect(a[p], a[j]);
            if(y != -1)
            {
                c = 0;
                break;
            }
            c++;
            p = j;
        }
        ans = max(ans, c);
    }
    cout << ans << '\n';
}