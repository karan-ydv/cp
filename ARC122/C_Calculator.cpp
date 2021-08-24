#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int n;
vector<int> ans;

bool recursion(int x, int y, int i)
{
    if(i > 130) return false;
    if(x == n)  return true;
    if(recursion(x + 1, y, i + 1))
    {
        ans.emplace_back(1);
        return true;
    }
    if(recursion(x, y + 1, i + 1))
    {
        ans.emplace_back(2);
        return true;
    }
    if(recursion(x + y, y, i + 1))
    {
        ans.emplace_back(3);
        return true;
    }
    if(recursion(x, x + y, i + 1))
    {
        ans.emplace_back(4);
        return true;
    }
    return false;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    recursion(0, 0, 0);
    cout << ans.size() << '\n';
    for(int x: ans) cout << x << '\n';
}