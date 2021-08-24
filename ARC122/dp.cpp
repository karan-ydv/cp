#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int countVowelStrings(int n) {
        vector<int> v(5, 1);
        for(int i = 1; i < n; i++)
        {
            for(int j = 4; j >= 0; j--)
            for(int k = 0; k < j; k++)
                v[j] += v[k];
        }
        for(int x: v) cerr << x << ' ';
        int ans = 0;
        for(int i = 0; i < 5; i++)
            ans += v[i];
        return ans;
    }

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << countVowelStrings(2);
}