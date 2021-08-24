#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;	cin >> t;
    while(t--)
    {
        int n;	cin >> n;
        unordered_map<int, int> mp;
        for(int i = 2; ;i++)
        {
            int x = n % i;
            if(mp.count(x))
            {
                cout << mp[x] << ' ' << i << '\n';
                break;
            }
            mp[x] = i;
        }
    }
}