#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n, k;
    cin >> n >> k >> s;

    int idx = n;
    for (int i = 1; i < n; i++)
        if (s[i] > s[0])
        {
            idx = i;
            break;
        }
        else if (s[i] == s[0])
        {
            int j = 0, k = i;
            bool flag = false;
            for (; k < n; k++)
            {
                if (s[k] < s[j])
                    break;
                else if (s[j] < s[k])
                {
                    flag = true;
                    break;
                }
                (j += 1) %= i;
            }
            if (flag)
            {
                idx = i;
                break;
            }
        }

    string t = s.substr(0, idx);
    while (t.length() < k)
        t += t;

    cout << t.substr(0, k);
}