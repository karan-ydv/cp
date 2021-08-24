#include <bits/stdc++.h>
using namespace std;

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
 
    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int, int, custom_hash> mp;
queue<int> q;

void add(int x)
{
    q.push(x);
    mp[x]++;
}
void pop()
{
    int x = q.front();
    q.pop();
    mp[x]--;
    if(mp[x] == 0)
        mp.erase(x);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    int a[n];   for(int &x: a)  cin >> x;
    int64_t ans = 0;
    int L = -1, R = 0;
    for(int i = 0; i < n; i++)
    {
        while(R < n and mp.size() <= k)
        {
            if(mp.size() == k and !mp.count(a[R]))
                break;
            add(a[R++]);
        }
        ans += R - i;
        pop();
    }
    cout << ans;
}