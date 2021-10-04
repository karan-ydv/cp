#include <bits/stdc++.h>
#define int int64_t
using namespace std;

struct Queue {
    map<char, int> mp;
    queue<char> q;
    bool push(char c) {
        q.push(c);
        mp[c]++;
        while(mp.size() > 2)
        {
            char f = q.front();
            q.pop();
            mp[f]--;
            if(mp[f] == 0)  mp.erase(f);
        }
        if(mp.size() == 2)
        {
            int a = mp.begin() -> second;
            int b = mp.rbegin() -> second;
            if(3 * a > a + b or 3 * b > a + b) {
                cerr << mp.begin() -> first << ' ' << mp.rbegin() -> first  << '\n';
                return true;
            }
        }
        return false;
    }
};

int solve(string A) {
    Queue q1, q2;
    for(char c: A) {
        if(q1.push(c))   return 1;
    }
    reverse(A.begin(), A.end());
    for(char c: A) {
        if(q2.push(c))   return 1;
    }
    return 0;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;   cin >> s;
    cout << solve(s);
}