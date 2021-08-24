#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int consecutiveones(vector<bool> v, int k)
{
    int ans = 0, zeroes = 0;
    int lptr = 0, rptr = 0;
    while(rptr < v.size())
    {
        if(v[rptr] == false)
            zeroes++;
        rptr++;
        while(zeroes > k)
        {
            if(v[lptr] == false)
                zeroes--;
            lptr++;
        }
        ans = max(ans, rptr - lptr);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<bool> v(n);
    // for(int i = 0; i < n; i++)
    // {
    //     int x;  cin
    // }
}