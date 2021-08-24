#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define int long long
#define cheetah ios_base::sync_with_stdio(NULL);cin.tie(0);cout.tie(0)
#define deb1(x) cout<<'['#x<<':'<<x<<']'<<' '; 
#define deb2(x,y) cout<<'['#x<<':'<<x<<' '#y<<':'<<y<<']';
#define ff first
#define ss second
#define eb emplace_back
#define pb push_back
#define all(v) v.begin(),v.end()
#define endl ('\n')
 
template<typename T>
using ordered_set =  tree<T ,null_type,less<T> ,rb_tree_tag,tree_order_statistics_node_update> ;
template<typename T>
//WARNING - for multiset lower_bound works as upper_bound
using ordered_multiset =  tree<T ,null_type,less_equal<T> ,rb_tree_tag,tree_order_statistics_node_update> ;
//  *(set_name.find_by_order(k))    set_name.order_of_key(k)
// ordered_set<int> name || ordered_multiset<int> name  syntax for template

unordered_map<int,bool> visited;

void dfs(int nodeN,vector<set<int> > &g,set<int> &nodes,vector<int> &tempV,int small){
    
    if(nodeN!=small)
        tempV.pb(nodeN);

    visited[nodeN] = true;
    for(auto it:g[nodeN]){
        if(visited[it]) continue;
       
        g[it].erase(small);
        visited[it] = true;
    
        if(g[it].size() > 0)
            dfs(it,g,nodes,tempV,small);   
        else
            nodes.erase(it);     
    
    }
} 

int check(vector<set<int> > &g,int no){

    if(g[no].size() == 0) return 1;
    auto it = g[no].end();
    it--;
    if(*it > no) return 0;

    return 1;
}

void option1(vector<set<int> > &g,int &ans){
    int u,v;cin>>u>>v;
    ans -=( check(g,u) + check(g,v));
    g[u].insert(v);
    g[v].insert(u);
    ans += (check(g,u) + check(g,v));
}

void option2(vector<set<int> > &g,int &ans){
    int u,v;cin>>u>>v;
    ans -= (check(g,u) + check(g,v));
    g[u].erase(v);
    g[v].erase(u);
    ans += (check(g,u) + check(g,v));
}

int32_t main (){
    cheetah;
    cout<<fixed;
    cout.precision(10);
    int t = 1;

    while(t--){
        int n,m;
        cin>>n>>m;

        vector<set<int> > g(n+10);
        set<int> nodes;

        int ans = n;

        for(int i = 0;i<m;i++){
            int u,v;cin>>u>>v;
            
            ans -= (check(g,u) + check(g,v));
            
            g[u].insert(v);
            g[v].insert(u);
            
            ans += (check(g,u) + check(g,v));

            nodes.insert(u);
            nodes.insert(v);
        }

        int q;cin>>q;
        while(q--){
            int op1;cin>>op1;
            if(op1 == 1){
                option1(g,ans);
            }
            else if(op1 == 2){
                option2(g,ans);
            }
            else{
                // cout<<abs(ans)<<endl;
                cout<<ans<<endl;
            }
        }
 
    }
    return 0;
}