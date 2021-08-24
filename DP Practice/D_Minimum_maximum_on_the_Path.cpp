#define pii pair<int,int>
#include <bits/stdc++.h>
using namespace std;
#define s second
#define f first

int n, m, d;
vector<pii> graph[100005];
vector<int> pred(100005);
bool bfs(int mx)
{
    queue<int> q;
    vector<bool> vis(n, 0);
    vector<int>  dis(n, 0);
    q.push(0);  vis[0] = 1;
    while( !q.empty() )
    {
        int x = q.front();
        if( dis[x] == d )
            return false;
        for(auto adj:graph[x])
        if( !vis[adj.f] and adj.s <= mx)
        {
            vis[adj.f] = true;
            dis[adj.f] = dis[x]+1;
            pred[adj.f] = x;
            if( adj.f == n-1 )
                return true;
            q.push(adj.f);
        }
        q.pop();
    }
    return false;
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m >> d;

    for(int i=0;i<m;i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a-1].push_back({b-1,c});
    }

    int ans=-1, beg = 0, end = 1e9, mid;
    while(beg<=end)
    {
        mid = (beg+end)/2;
        if(bfs(mid))
        {
            ans = mid;
            end = mid-1;
        }
        else beg = mid+1;
    }
    if( ans!=-1 )
    {
        int x = n - 1;
        pred[0] =  -1;
        bfs(ans);
        stack<int> s;
        while( x!=-1 )
        {
            s.push(x+1);
            x = pred[x];
        }
        cout << s.size()-1 << '\n';
        while(!s.empty())
        {
            cout << s.top() << ' ';
            s.pop();
        }
    }
    else cout << "-1";
}