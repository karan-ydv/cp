#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct LRUCache {
    typedef pair<int, int> pii;
    int N;
    list<pii> L;
    unordered_map<int, list<pii>::iterator> mp;
    LRUCache(int capacity): N(capacity) {}
    
    int get(int key)
    {
        auto itr = mp.find(key);
        if(itr != mp.end())
        {
            // L.splice(L.begin(), L, itr -> second);
            return itr -> second -> second;
        }
        return -1;
    }
    
    void put(int key, int value)
    {
        auto itr = mp.find(key);
        if(itr != mp.end())
        {
            L.splice(L.begin(), L, itr -> second);
            itr -> second -> second = value;
        }
        else
        {
            if((int)L.size() == N)
            {
                mp.erase(L.back().first);
                L.pop_back();
            }
            L.push_front({key, value});
            mp[key] = L.begin();
        }
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n, k;   cin >> n >> k;
    LRUCache cac(k);
    for(int i = 0; i < n; i++) {
        int x;  cin >> x;
        if(cac.get(x) == -1)
            cac.put(x, 0);
    }
    cout << cac.L.size() << '\n';
    for(auto [x, f]: cac.L)
        cout << x << ' ';
}