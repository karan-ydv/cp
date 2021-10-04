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
        int a[n][26], b[26][n];
        for(int i = 0; i < n; i++) {
            string s;   cin >> s;
            for(char c: s) a[i][c - 'a']++;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++)
        {
            priority_queue<pair<int, int>>
            /*
            while(freq[i] <= freq[Max])
            {
                // get the row which has
            }
            */
        }
    }
}