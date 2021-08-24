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
        int n, m, k;    cin >> n >> m >> k;
        int p[n], A[n];
        for(int &x: p)  cin >> x;
        iota(A, A + n, 0);
        sort(A, A + n, [&](int x, int y){
            return p[x] < p[y];
        });
        // for(int x: A)   cerr << x << ' ';
        // cerr << endl;
        int T = p[A[0]];
        // cerr << T << ": ";
        bool flag = false;
        string ans = "NO";
        for(int i = 0; i < n and m > 0; )
        {
            int j;
            for(j = i; j < n; j++)
            {
                if(p[A[j]] != p[A[i]]) break;
                if(A[j] == 0) flag = true;
            }
            // cerr << j << endl;
            if(m >= (j - i))
            {
                m -= (j - i);
                T += k * (j - i);
                if(flag)
                {
                    ans = "YES";
                    break;
                }
            }
            else
            {
                m = 0;
                if(flag)
                ans = "MAYBE";
            }
            i = j;
        }
        // cerr << endl;
        cout << ans << '\n';
    }
}