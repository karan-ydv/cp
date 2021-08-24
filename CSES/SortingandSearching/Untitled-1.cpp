#include<bits/stdc++.h>
using namespace std;long long n,x,z,s,q,a;map<long long,int>f;int main(){cin>>n>>z;f[0]=1;for(;n;--n){cin>>q,s+=q;a+=f[s-z];f[s]++;}cout<<a;}