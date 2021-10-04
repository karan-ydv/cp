#include <bits/stdc++.h>
using namespace std;

int solution(vector<int> &A, int M) {
    map<int, int> mp;
    int ans = 0;
    for(int x: A) {
        x %= M;
        (x += M) %= M;
        ans = max(ans, ++mp[x]);
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {-3, -2, 1, 0, 8, 7, 1};
    cout << solution(v, 3);
}