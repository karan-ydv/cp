#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+5;
int C[N], D[N];
stack<int> stk;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    string s;   cin >> s;
    int n = s.length(); s = "!" + s;
    int ans = 0, cnt = 0;
    D[0] = -1;
    for(int i = 1; i <= n; i++)
    {
        if(s[i] == '(') stk.push(i), D[i] = -1;
        else
        {
            if(stk.empty())
                C[i] = D[i] = -1;
            else
            {
                C[i] = stk.top();
                D[i] = D[C[i] - 1];
                if(D[i] == -1)  D[i] = C[i];
                if(i - D[i] + 1 == ans)
                    cnt++;
                else if(i - D[i] + 1 > ans)
                    ans = i - D[i] + 1, cnt = 1;
                stk.pop();
            }
            // cerr << i << ' ' << D[i] << '\n';
        }
    }
    if(ans == 0)    cnt = 1;
    cout << ans << ' ' << cnt;
}