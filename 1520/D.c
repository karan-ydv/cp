#include <stdio.h>
#include <stdlib.h>
#define N 300005
// const int N = 3e5+5;

int max(int a, int b) {
    return a > b ? a : b;
}

typedef struct node node;
typedef struct queue queue;

struct node{
    int x;
    node* nxt;
};

node* newnode(int v) {
    node* n = (node*)malloc(sizeof(node));
    n -> x = v;
    n -> nxt = NULL;
    return n;
}

/* queue */
struct queue{
    int size;
    node* front;
    node* end;
};

queue* newque() {
    queue* q = (queue*)malloc(sizeof(queue));
    q -> front = NULL;
    q -> end = NULL;
    q -> size = 0;
    return q;
}

void push(queue* q, int x) {
    ++ q -> size;
    if(q -> size == 1)
    {
        q -> front = newnode(x);
        q -> end = q -> front;
        return;
    }
    q -> end -> nxt = newnode(x);
    q -> end = q -> end -> nxt;
}
void pop(queue* q) {
    -- q -> size;
    q -> front = q -> front -> nxt;
    if(q -> front == NULL)
        q -> end = NULL;
}
/* ..... */

char S[N];
int deg[N];
int dp[N][26];
node* adj[N];
node* lst[N];

void addedge(int u, int v) {
    if(lst[u] == NULL)
    {
        adj[u] = newnode(v);
        lst[u] = adj[u];
        return;
    }
    lst[u] -> nxt = newnode(v);
    lst[u] = lst[u] -> nxt;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", S + 1);
    for(int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        addedge(u, v);
        --deg[v];
    }

    int ans = -1, i;
    queue *q = newque();

    for(int i = 1; i <= n; i++)
    if(deg[i] == 0) push(q, i);

    for(i = 0; i < n && q -> size > 0; i++)
    {
        int u = q -> front -> x;
        pop(q);
        dp[u][S[u] - 'a'] += 1;
        for(int j = 0; j < 26; j++)
            ans = max(ans, dp[u][j]);
        node* f = adj[u];
        while(f != NULL)
        {
            int v = f -> x;
            for(int j = 0; j < 26; j++)
                dp[v][j] = max(dp[v][j], dp[u][j]);
            ++deg[v];
            if(deg[v] == 0)
                push(q, v);
            f = f -> nxt;
        }
    }

    if(q -> size > 0 || i < n)
        ans = -1;
    printf("%d", ans);
}