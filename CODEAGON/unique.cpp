#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int solution(vector<int> &A) {
    sort(A.begin(), A.end());
    int ans = 0;
    for(int i = 0; i < A.size(); i++) {
        ans += abs(A[i] - i - 1);
        if(ans > 1e9)   return -1;
    }
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {1, 2, 1};
    cout << solution(v);

}