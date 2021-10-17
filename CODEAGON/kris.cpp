#include <bits/stdc++.h>
using namespace std;

struct Graph 
{
    typedef int item;
    vector<vector<item>> adj;
    vector<bool> firstBencher;
    int V;
    Graph(int n) : V(n) {
        adj.resize(n + 1);
        firstBencher.resize(n + 1);
    }
    pair<int, int> DFS(int u, int p)
    {
        if(adj[u].size() <= 1)
            return {!firstBencher[u], !firstBencher[u]};
        
        int x = 0, y = 0;
        priority_queue<int> heap;
        for(auto v: adj[u]) if(v != p)
        {
            auto [a, b] = DFS(v, u);
            x = max(x, a);
            y = max(y, b);
            heap.push(-b);
            if(heap.size() > 2)
                heap.pop();
        }
        if(firstBencher[u])
            return {x, 0};
        
        int z = 1;
        while(!heap.empty()) {
            z -= heap.top();
            heap.pop();
        }

        x = max({x, z, ++y});
        return {x, y};
    }
    int solve()
    {
        int x = DFS(1, -1).first;
        return x ? x - 1 : x;
    }
};

int cheat(int input1, int input2[][2], int input3, int input4[])
{
    Graph g(input1);
    for(int i = 0; i < input1 - 1; i++) {
        int u = input2[i][0];
        int v = input2[i][1];
        g.adj[u].emplace_back(v);
        g.adj[v].emplace_back(u);
    }
    for(int i = 0; i < input3; i++)
        g.firstBencher[input4[i]] = 1;
    return g.solve();
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n = 10;
    int edg[9][2] = {{1, 2}, {1, 8}, {2, 3}, {2, 4}, {4, 5}, {4, 6}, {6, 7}, {8, 9}, {8, 10}};
    int k = 2;
    int first[2] = {1, 2};
    cout << cheat(n, edg, k, first);
}