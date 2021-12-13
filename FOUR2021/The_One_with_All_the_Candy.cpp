/*
#include <bits/stdc++.h>
#define int int64_t
using namespace std;

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    // int t;	cin >> t;
    // while(t--)
    // {
    //     int n;	cin >> n;
    //     int a[n];   for(int &x: a)  cin >> x;
    //     int x = *min_element(a, a + n);
    //     int ans = n * x, cnt = 0, mx = 0;
    //     for(int i = 0; i < n + n; i++)
    //     {
    //         cnt += a[i % n] > x;
    //         mx = max(mx, cnt);
    //         if(a[i % n] == x) cnt = 0;
    //     }   
    //     ans += mx;
    //     cout << ans << '\n';
    // }
    int x = 123 / 5;
    x += 123 / 25;
    cout << x;
}
*/
#include<bits/stdc++.h>
#include <iterator>
#include <iostream>
#include <numeric>
#include <math.h>
#define ll long long
#define ull long
#define mpa make_pair
#define pb push_back
#define ff first
#define pii pair<ll,ll>
#define dd long double
#define trace(x) cerr << #x << " : " << x << endl
#define ss second
#define boost ios_base::sync_with_stdio(0)
#define forp(i,a,b) for(ll i=a;i<=b;i++)
#define rep(i,n)    for(ll i=0;i<n;++i)
#define ren(i,n)    for(ll i=n-1;i>=0;i--)
#define forn(i,a,b) for(ll i=a;i>=b;i--)
#define all(c) (c).begin(),(c).end()
#define tr(c,i) for(typeof((c).begin()) i = (c).begin(); i != (c).end();
#define sc(x) scanf("%lld",&x)
#define clr(x,val) memset(x,val,sizeof(x))
#define pr(x) printf("%lld\n",x) 
#define gc getchar
#define pdd pair<dd,dd>
#define prec(x) cout<<fixed<<setprecision(x)
#define fre freopen("input.txt","r",stdin),freopen("output.txt","w",stdout)
#define arr array 
using namespace std;
ll a[200005];
void solve(){
    ll n;
    cin>>n;
    ll mi=1e14;
    for(ll i=1;i<=n;i++){
       cin>>a[i];
       mi=min(mi,a[i]);
    }

    ll c_mi=0;
    for(ll i=1;i<=n;i++){
        if(a[i]==mi){
           c_mi++;
        }
    }

   // cout<<mi<<" "<<c_mi<<endl;

    ll ans=n*mi+(n-c_mi);


    cout<<ans<<endl;




    
}
    
		
int main(){
    boost;

    //pre_cum();
    //prec(20);
	//fre;


 



    ll t=1;
    ll tc=1;
    cin>>t;

	while(t--){
		solve();
        tc++;
	}

    return 0;
    
     
}
  