/**此代码借鉴了某大神的，我看懂了后又分析的*/
#include<bits/stdc++.h>
#include <vector>
using namespace std;
typedef long long ll;
const int MAXN = 5e5 + 10;

int n, k, Max, root;
ll ans;
vector <int> tree[MAXN];
vector <int> sta;
int sz[MAXN], maxv[MAXN], a[MAXN];
ll Hash[1200];
bool vis[MAXN];

void init()
{
    memset(vis, false, sizeof(vis));
    for (int i = 1; i <= n; i++) tree[i].clear();
}

void dfs_size(int u, int pre)
{
    sz[u] = 1;
    maxv[u] = 0;
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++)
    {
        int v = tree[u][i];
        if (v == pre || vis[v]) continue;
        dfs_size(v, u);
        sz[u] += sz[v];
        maxv[u] = max(maxv[u], sz[v]);
    }
}

void dfs_root(int r, int u, int pre)
{
    maxv[u] = max(maxv[u], sz[r] - sz[u]);
    if (Max > maxv[u])
    {
        Max = maxv[u];
        root = u;
    }
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++)
    {
        int v = tree[u][i];
        if (v == pre || vis[v]) continue;
        dfs_root(r, v, u);
    }
}
void dfs_sta(int u, int pre, int s)
{
    sta.push_back(s);
    int cnt = tree[u].size();
    for (int i = 0; i < cnt; i++)
    {
        int v = tree[u][i];
        if (v == pre || vis[v]) continue;
        dfs_sta(v, u, s | (1 << a[v]));
    }
}

ll cal(int u, int s)
{
    ll res = 0;
    sta.clear();
    dfs_sta(u, -1, s);
    memset(Hash, 0, sizeof(Hash));
    int cnt = sta.size();
   /**暴力去跑
    for(int i=0;i<cnt;i++)
    {
        for(int j=i+1;j<cnt;j++)
        {
            if(sta[i]|sta[j]==((1<<k)-1))
                res+=2;
        }
    }*/
    for (int i = 0; i < cnt; i++) Hash[sta[i]]++;
    for (int i = 0; i < cnt; i++)
    {
        Hash[sta[i]]--;///减去自身值
        res += Hash[(1 << k) - 1];///i点到状态为((1<<k)-1)肯定符合，所以直接加上
        for (int s0 = sta[i]; s0; s0 = (s0 - 1) & sta[i])///枚举i节点状态子集
        {
            res += Hash[((1 << k) - 1) ^ s0];
        }
        Hash[sta[i]]++;
    }
    return res;
}

void dfs(int u)
{
    Max = n;
    dfs_size(u, -1);
    dfs_root(u, u, -1);
    ans += cal(root, (1 << a[root]));
    vis[root] = true;
    int cnt = tree[root].size(), rt = root;
    for (int i = 0; i < cnt; i++)
    {
        int v = tree[rt][i];
        if (vis[v]) continue;
        ans -= cal(v, (1 << a[rt]) | (1 << a[v]));
        dfs(v);
    }
}

int main()
{
    while (scanf("%d%d", &n, &k) == 2)
    {
        init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i]);
            --a[i];
        }
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        if (k == 1)
        {
            printf("%d\n", n * n);
            continue;
        }
        ans = 0;
        dfs(1);
        printf("%lld\n", ans);
    }
    return 0;
}
