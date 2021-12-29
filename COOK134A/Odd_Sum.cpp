#include<bits/stdc++.h>
using namespace std;
// #define int  long long


int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
     int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    if(n<=2) cout<<1;
    else {
        n-=2;
        long long ans =n*(n+1);
        cout<<ans+1;
    }
    cout<<endl;
    
}
}