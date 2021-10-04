#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int val) : val(val), left(NULL), right(NULL) {};
};

typedef vector<pair<int, int>> vp;
vp fun(node* root) {
    if(root == NULL) return {{0, 0}};
    vp L = fun(root -> left);
    vp R = fun(root -> right);
    vp res;
    for(auto [a, b]: L)
    for(auto [x, y]: R)
        res.emplace_back(a + x, b + y);
    res.emplace_back(L.back().first + R.back().first + root -> val, 
                     L.back().second + R.back().second + 1);
    return res;
}

node* createTree(vector<int> &v) {
    node* root = new node(v[0]);
    queue<node*> q;
    q.push(root);
    for(int i = 1; i < v.size(); i++)
    {
        node *n = new node(v[i]);
        if(!q.front() -> left)
            q.front() -> left = n;
        else
        {
            q.front() -> right = n;
            q.pop();
        }
        q.push(n);
    }
    return root;
}

int minimumCost(vector<int> numberList) {
    node *root = createTree(numberList);
    vp L = fun(root -> left);
    vp R = fun(root -> right);

    int sumLeft = L.back().first;
    int sumRight = R.back().first;

    map<int, int> mp1, mp2;
    for(auto [a, b]: L) {
        a = sumLeft - a;
        if(!mp1.count(a))
            mp1[a] = b;
        else
            mp1[a] = min(mp1[a], b);
    }
    for(auto [a, b]: R) {
        a = sumRight - a;
        if(!mp2.count(a))
            mp2[a] = b;
        else
            mp2[a] = min(mp2[a], b);
    }


    int ans = 1e9;
    for(auto [x, f]: mp1) if(mp2.count(x)) {
        ans = min(ans, f + mp2[x]);
    }
    
    ans *= 10;
    return ans;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    vector<int> v = {4, 2, 6, 1, 3, 5};
    cout << minimumCost(v);
}