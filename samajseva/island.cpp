#include <bits/stdc++.h>
using namespace std;

const pair<int, int> d4[] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        auto invalid = [&](int i, int j) {
            return i < 0 or i >= n or j < 0 or j > m;
        };
        
        int count = 0;
        queue<pair<int, int>> q;
        for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
        if(grid[i][j] == 2)
            q.push({i * m + j, 0});
        else
            count += grid[i][j];
        
        if(q.empty())   return -1;
        int ans = 0;
        count += q.size();
        while(!q.empty())        
        {
            auto [a, d] = q.front(); q.pop();
            int x = a / m, y = a % m;
            if(grid[x][y] == 0) continue;
            ans = d;
            count--;
            grid[x][y] = 0;
            for(auto [dx, dy]: d4)
            {
                int i = x + dx, j = y + dy;
                if(invalid(i, j)) continue;
                if(grid[i][j] != 1) continue;
                q.push({i * m + j, d + 1});
            }
            
        }
        if(count == 0)
            return ans;
        return -1;
        
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<vector<int>> v{{2,1,1},{1,1,0},{0,1,1}};
    // vector<vector<int>> v{{2,1,1},{0,1,1},{1,0,1}};
    // vector<vector<int>> v{{0,2}};
    cout << Solution().orangesRotting(v);
}