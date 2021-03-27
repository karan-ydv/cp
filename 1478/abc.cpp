#include<bits/stdc++.h>
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
     
     struct segtree{
         int size ;
         vector<int> sums;
         void init(int n){
             size = 1;
             while (size<n) size *= 2 ;
             sums.assign(2*size,0ll);
         }
         void set(int i ,int  v,int x, int lx ,int rx){
             if(rx - lx ==1  )
             {
                 sums[x] = v;
                 return ;

             }
             int m = (lx+rx)/2;
             if (i < m ) {
                 set(i,v,2*x+1,lx,m);
             }
             else {
                 set(i,v,2*x+2,m,rx);
             }
             sums[x] = sums[2*x+1] + sums[2*x+2];
         }
        void set(int i,int v){
                set(i,v,0ll,0ll,size);
        }
        int sum (int l,int r,int x,int lx ,int rx){
            if (lx >= r or l >= rx){
                return 0;
            }
            if (lx >= l and rx<=r ) return sums[x];
            int m= (lx+rx)/2;
            return sum(l,r,2*x+1,lx,m)+sum(l,r,2*x+2,m,rx);
        }
    int sum (int l , int r){
        return sum(l,r ,0ll,0ll,size);
    }
     };
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
     while (t--){
         
     
     int n,k;
     cin>>n>>k;
     int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int sum = a[0] ;
    int mx =-1;
    int in=-1;
    int ans=0;
    for(int i=1;i<n;i++){
         int x = (a[i]*100)-(k*sum);
     if(x<=0) x=0;
    else {
        x=ceil((double)x/k);
    }
    ans +=x;
    sum+=(a[i]+x);
   
        
    }
 
    cout<<ans<<endl;
     }
     
}