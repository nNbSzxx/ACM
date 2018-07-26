#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<LL, int> PLLI;
const int MAX = 1e5 + 10;
const LL INF = 0x3f3f3f3f3f3f3f3f;
int head[MAX], cnt, n, m, k, a[MAX], mark[MAX], vis[MAX];
LL dis[MAX];
priority_queue<PLLI, vector<PLLI>, greater<PLLI>> q;
struct edge {
    int v, w, nt;
} e[MAX * 2];

void init()
{
    cnt = 1;
    memset(head, 0, sizeof head);
    memset(mark, 0, sizeof mark);
}
void add(int u, int v, int w)
{
    e[cnt].v = v;
    e[cnt].w = w;
    e[cnt].nt = head[u];
    head[u] = cnt ++;
    return ;
}
LL dij()
{
    while (!q.empty()) {
        PLLI p = q.top(); q.pop();
        int u = p.second;
        LL d = p.first;
        vis[u] = 1;
        if (mark[u]) return d;
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (vis[v]) continue;
            if (dis[v] > d + 1LL * e[i].w) {
                dis[v] = d + 1LL * e[i].w;
                q.push(PLLI(dis[v], v));
            }
        }
    }
    return INF;
}
void solve(int t)
{
    LL ans = INF;
    //printf("%lld\n", ans);
    for (int i = 0; i <= int(log2(k) + 0.05); i ++) {
        while (!q.empty()) q.pop();
        memset(vis, 0, sizeof vis);
        memset(mark, 0, sizeof mark);
        memset(dis, 0x3f, sizeof dis);
        //cout << "pick: ";
        for (int j = 1; j <= k; j ++) {
            if (j & (1 << i)) {
                mark[a[j]] = 1;
                //cout << a[j] << " ";
            } else {
                vis[a[j]] = 1;
                dis[a[j]] = 0;
                q.push(PLLI(0, a[j]));
            }
        }
        //cout << endl;
        LL temp = dij();
        //cout << temp << endl;
        ans = min(ans, temp);
        //cout << ans << endl;
        //cout << "pick: ";
        while (!q.empty()) q.pop();
        memset(vis, 0, sizeof vis);
        memset(dis, 0x3f, sizeof dis);
        memset(mark, 0, sizeof mark);
        for (int j = 1; j <= k; j ++) {
            if (j & (1 << i)) {
                vis[a[j]] = 1;
                dis[a[j]] = 0;
                q.push(PLLI(0, a[j]));
            } else {
                //cout << a[j] << " ";
                mark[a[j]] = 1;
            }
        }
        temp = dij();
        ans = min(ans, temp);
        //cout << endl << temp << endl;
    }
    printf("Case #%d: %lld\n", t, ans);
}
int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        init();
        scanf("%d%d", &n, &m);
        int u, v, w;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i ++) {
            scanf("%d", &a[i]);
        }
        solve(tc ++);
    }
}
