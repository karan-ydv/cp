// #include <bits/stdc++.h>
// #define int int64_t
// using namespace std;

// int fun(string s1, string s2)
// {
//     // cerr << s1 << ' ' << s2 << " : ";
//     int j = 0, c = 0;
//     for(int i = 0; i < s1.length(); i++)
//     {
//         if(j < s2.length() and s1[i] == s2[j])  j++;
//         else    c++;
//     }
//     // cerr << c + (s2.length() - j) << '\n';
//     return c + (s2.length() - j);
// }

// int32_t main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
//     int t;	cin >> t;
//     while(t--)
//     {
//         int n;	cin >> n;
//         int ans = 2e9;
//         string s = to_string(n);
//         for(int i = 0; i <= 60; i++)
//             ans = min(ans, fun(s, to_string(1ll << i)));
//         cout << ans << '\n';
//     }
// }
#include<bits/stdc++.h>
// #include <boost/multiprecision/cpp_int.hpp>
// using namespace boost::multiprecision;
using namespace std;
#define int  long long
#define vc vector<int> 
#define F first
#define S second
#define eb emplace_back

int power(int x, int y, int p) 
{ 
    int res = 1;      
    x = x % p;  
    while (y > 0) 
    { 
      
        if (y & 1) 
            res = (res*x) % p; 
  
        
        y = y>>1; // y = y/2 
        x = (x*x) % p; 
    } 
    return res; 
} 
  

int modInverse(int n, int p) 
{ 
    return power(n, p-2, p); 
} 
  
 
int nCrModPFermat(int n, int r, int p) 
{ 
 
   if (r==0) 
      return 1; 
  
   
    int fac[n+1]; 
    fac[0] = 1; 
    for (int i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%p; 
  
    return (fac[n]* modInverse(fac[r], p) % p * 
            modInverse(fac[n-r], p) % p) % p; 
} 
/*
// dsu started 
int a[1000000],b[1000000];
    int find(int x){
        if(b[x]==x) return x;
        b[x]= find(b[x]);
      return b[x];
    }
    void uniona(int x,int y){
        x=find(x);
        y=find(y);
        if (x!=y) {
            a[y]<a[x] ? b[x]=b[y]:b[y]=b[x];
        }
    }
//cut from here
int n,k;
    cin>>n>>k;
     
   
     for(int i=1;i<=n;i++){
    cin>>a[i];
    b[i]=i;
    }
     for(int i=1;i<=k;i++){
    int t1,t2;
    cin>>t1>>t2;// basic code for dsu
    uniona(t1,t2);
//dsu ends
*/



class Tree{
  vector<vc>  g;
  vc vis;
  vc a;
  map<int,vector<int>> mp;
    void init(int n,int m ){
       g=  vector<vc> (n+1,vc());
       a=vc(n+1);
       vis=vc(n+1,0);
       for(int i=0;i<n;i++){
           cin>>a[i+1];
       }
       while(m--){
           int x,y;
           cin>>x>>y;
           g[x].eb(y);
           g[y].eb(x);
       }
       
       
  }
  
  void dfs(int s,int c){
      vis[s]=1;
      mp[c].eb(a[s]);
      for(int i:g[s]){
          if(!vis[i]) dfs(i,c);
      }
  }
//   int cal(){
//       int ans =0;
//       for(auto &[x,y]:mp){
//           if(y.size()%2){
//               int s=y[i].size()/2;
//               sort(y.begin(),y.end());
//               for(int i=0;i<y.size();i++){
//                   ans+=y[i];
//                   if(i<s) ans+=y[i];
//                   else if(i>s) ans-=y[i];
//               }
//           }
//       }
//   }
  
  
};
int fun(int n,int a){
    string x=to_string(n),y=to_string(a);
    // reverse(y.begin(),y.end());
    // reverse(x.begin(),x.end());
    
    int c=0;
    
    for(int i=0,j=0;i<x.length() and j<y.length(); i++){
        if(x[i]==y[j]) c++,j++;
    }
    return x.length()+y.length()-2*c;
        
   
}

void execute(){
int t;
cin>>t;
while(t--){
    
   int n;
   
   cin>>n;
   
   int c = INT_MAX,ans;
   for(int i=1;i<=(1ll<<60);i=i+i){
       int yy=fun(n,i);
       c=min(c,yy);
       if(i==0){i=1;continue;}
   }
   cout<<c<<endl;

        
    
    
}
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    execute();
}