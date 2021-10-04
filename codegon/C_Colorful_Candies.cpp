#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 69;
int A[N];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    unordered_map<int, int> mp;
    int n, k;   cin >> n >> k;
    for(int i = 0; i < k; i++) {
        cin >> A[i];
        mp[A[i]]++;
    }
    int ans = mp.size();
    for(int i = k; i < n; i++) {
        cin >> A[i];
        mp[A[i]]++;
        mp[A[i - k]]--;
        if(mp[A[i - k]] == 0)
            mp.erase(A[i - k]);
        ans = max(ans, (int)mp.size());
    }
    cout << ans;
}