#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int uniqueLetterString(string s) {
        int ans = 0;
        int n = (int) s.length();
        vector<int> A[26];
        for(int i = 0; i < 26; i++)
            A[i].emplace_back(0);
        for(int i = 0; i < n; i++)
            A[s[i] - 'A'].emplace_back(i + 1);
        for(int i = 0; i < 26; i++)
        {
            int m = (int) A[i].size();
            if(m == 1)  continue;
            A[i].emplace_back(n + 1);
            for(int j = 1; j < m; j++)
            {
                clog << A[i][j] << ' ';
                ans += (A[i][j] - A[i][j - 1]) * (A[i][j + 1] - A[i][j]);
            }
            clog << '\n';
        }
        return ans;
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout << Solution().uniqueLetterString("ABC");
}