#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solution(vector<int> &A, vector<string> &D) {
    int n = A.size();
    int ans = -60;
    for(int x: A)   ans += x;
    map<string, int> mp, cnt;
    for(int i = 0; i < n; i++) {
        string m = D[i].substr(5, 2);
        mp[m] += A[i];
        if(A[i] < 0)
            cnt[m]++;
    }
    for(auto [m, sum]: mp)
    if(sum > 99 and cnt[m] > 2)
        ans += 5;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;  cin >> n;
    vector<string> d(n);
    vector<int> a(n);
    for(auto &x: d) cin >> x;
    for(auto &x: a) cin >> x;
    cout << solution(a, d);
}