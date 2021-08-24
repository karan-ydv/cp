#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout<<fixed;cout.precision(10);
#define endl "\n"
#define tc ll T; cin >> T; while(T--)
#define pb push_back
#define mod 1000000007
#define S second
#define F first
#define int long long
using namespace std;
typedef long long ll;
const int N = 1e5+5;

int32_t main() {

    fastio;
    tc{ 
        int n; cin >> n;
        if(n <= 2){
            for(int i = 1; i <= n; i++) cout << i << " ";
            cout << endl;
            continue;
        }
        
        int ans[n];
        ans[0] = 1; ans[1] = 2;
        map<int, int> mp;
        int curr = 1, mx = 2;

        for(int i = 0; i < n; i += 2) ans[i] = 1;
        for(int i = 1; i < n; i += 2){
            int temp = -1;
            for(int j = 2; j <= mx; j++) if((mp[j] + 1) & 1){
                temp = j; break;
            }
            if(temp == -1) temp = mx+1, mx++;
            ans[i] = temp;
            for(int j = temp-1; j >= 2; j--) mp[j] = 0;
            mp[temp]++;
        }        

        for(auto i : ans) cout << i << " ";
        cout << endl;

    }



    return 0;
 
}