#include <iostream>
#define int long long
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    int t;  cin >> t;
    for(int _ = 0; _ < t; _++) {
        int n, e, h, a, b, c;
        cin >> n >> e >> h >> a >> b >> c;
        int ans = 1e15;
        // number of chocolate cakes
        for(int i = 0; i <= min(n, min(e, h)); i++) {
            int x = e - i;  // eggs left
            int y = h - i;  // chocolate bars left
            int omlettes = x / 2;   // max no. of omlettes that can be made
            int shakes = y / 3;     // max no. of shakes that can be made
            if(omlettes + shakes < n - i)
                continue;
            if(a == b)
            {
                ans = min(ans, i * c + (n - i) * a);
            }
            else if(a < b)
            {
                int om = min(n - i, omlettes);
                int sh = min(n - i - om, shakes);
                ans = min(ans, i * c + om * a + sh * b);
            }
            else
            {
                int sh = min(n - i, shakes);
                int om = min(n - i - sh, omlettes);
                ans = min(ans, i * c + om * a + sh * b);
            }
        }
        if(ans == 1e15)
            ans = -1;
        cout << ans << '\n';
    }
}