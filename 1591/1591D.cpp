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
        int a[n]; for(int &x: a)    cin >> x, x--;
        if(n < 3)
        {
            is_sorted(a, a + n) ? cout << "YES\n" : cout << "NO\n";
            continue;
        }
        unordered_set<int> set;
        bool flag = false;
        for(int x: a) {
            if(set.count(x))
            {
                flag = true;
                break;
            }
            set.insert(x);
        }
        if(flag)
        {
            cout << "YES\n";
            continue;
        }
        flag = true;
        for(int i = 0, c = 0; i < n - 1; )
        {
            if(c > 5 * n)
                break;
            if(i != a[i])
            {
                c++;
                int x = a[i];
                swap(a[i], a[a[i]]);
                if(i == a[i])
                {
                    int j = i;
                    for(; j < n; j++)
                    if(a[j] != j)
                    {
                        swap(a[i], a[j]);
                        break;
                    }
                    if(j == n)
                    {
                        swap(a[i], a[x]);
                        break;
                    }
                }
                else
                    swap(a[i], a[a[i]]);
            }
            else i++;
        }
        is_sorted(a, a + n) ? cout << "YES\n" : cout << "NO\n";
    }
}