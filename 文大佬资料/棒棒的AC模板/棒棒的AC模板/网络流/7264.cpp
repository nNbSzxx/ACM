#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e3+5;
const int maxv = 1e5 + 5;
int head[maxn], cur[maxn], d[maxn], s, t, k, sum;
int n, m, g;
struct node
{
    int v, w, next;
}edge[maxv];
void addEdge(int u, int v, int w)
{
    edge[k].v = v;
    edge[k].w = w;
    edge[k].next = head[u];
    head[u] = k++;
    edge[k].v = u;
    edge[k].w = 0;
    edge[k].next = head[v];
    head[v] = k++;

}
int bfs()
{
    memset(d, 0, sizeof(d));
    d[s] = 1;
    queue<int> q;
    q.push(s);
    while(!q.empty())
    {
        int u = q.front();
        if(u == t) return 1;
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next)
        {
            int to = edge[i].v, w = edge[i].w;
            if(w && d[to] == 0)
            {
                d[to] = d[u] + 1;
                if(to == t) return 1;
                q.push(to);
            }
        }
    }
    return 0;
}
int dfs(int u, int maxflow)
{
    if(u == t) return maxflow;
    int ret = 0;
    for(int i = cur[u]; i != -1; i = edge[i].next)
    {
        int to = edge[i].v, w = edge[i].w;
        if(w && d[to] == d[u]+1)
        {
            int f = dfs(to, min(maxflow-ret, w));
            edge[i].w -= f;
            edge[i^1].w += f;
            ret += f;
            if(ret == maxflow) return ret;
        }
    }
    return ret;
}
int Dinic()
{
    int ans = 0;
    while(bfs() == 1)
    {
        memcpy(cur, head, sizeof(head));
        ans += dfs(s, INF);
    }
    return ans;
}
int main()
{
    int T;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d%d%d", &n, &m, &g);
        s = 0, t = n*2+1, k = 0;
        memset(head, -1, sizeof(head));
        int x, y, z;
        for(int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &x, &y, &z);
            addEdge(n+x, y, z);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            addEdge(s, i, x);
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%d", &x);
            addEdge(i, i+n, x);
        }
        addEdge(g+n, t, INF);
        printf("%d\n", Dinic());
    }
    return 0;
}

