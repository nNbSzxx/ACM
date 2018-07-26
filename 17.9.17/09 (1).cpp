#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3F3F3F3F;
const int MAXN = 210;
const int MAXM = 1010;
class CNode {
   public:
    int x, w, nex;
} edge[MAXM << 1];
int n, m, s, t, cnt, MEMORY_SIZE;
int h[MAXN], cur[MAXN], dis[MAXN];
queue<int> Q;
inline void add(int u, int v, int w) {
    edge[cnt].x = v;
    edge[cnt].w = w;
    edge[cnt].nex = h[u];
    h[u] = cnt++;
}
inline void init() {
    memset(h, -1, sizeof h);
    cnt = 0;
    scanf("%d%d%d%d", &n, &m, &s, &t);
    int u, v, w;
    for (int i = 0; i < m; ++i) {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w);
        add(v, u, 0);
    }
    MEMORY_SIZE = (n + 1) * sizeof(int);
}
inline int mmin(int a, int b) { return a < b ? a : b; }
inline bool bfs(int s, int t) {
    int u, v;
    memset(dis, -1, sizeof dis);
    Q.push(s);
    dis[s] = 0;
    while (!Q.empty()) {
        u = Q.front();
        Q.pop();
        for (int i = h[u]; ~i; i = edge[i].nex) {
            v = edge[i].x;
            if (dis[v] == -1 && edge[i].w) {
                dis[v] = dis[u] + 1;
                Q.push(v);
                if (v == t) break;
            }
        }
    }
    return (dis[t] != -1);
}
inline int dfs(int u, int t, int cap) {
    if (u == t || cap == 0) return cap;
    int res = 0, flow;
    for (int &i = cur[u]; ~i; i = edge[i].nex) {
        int v = edge[i].x;
        if (dis[v] == dis[u] + 1 && (flow = dfs(v, t, mmin(cap - res, edge[i].w))) > 0) {
            edge[i].w -= flow;
            edge[i ^ 1].w += flow;
            res += flow;
            if (res == cap) return cap;
        }
    }
    if (!res) dis[u] = -1;
    return res;
}
inline int dinic(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
        memcpy(cur + 1, h + 1, MEMORY_SIZE);
        ans += dfs(s, t, INF);
    }
    return ans;
}
int main() {
    // freopen("in.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while (T--) {
        init();
        dinic(s, t);
        for (int i = 0; i < cnt; i += 2)
            if (edge[i].w) {
                edge[i].w = INF;
                edge[i ^ 1].w = 0;
            }
            else {
                edge[i].w = 1;
                edge[i ^ 1].w = 0;
            }
        printf("%d\n", dinic(s, t));
    }
    return 0;
}
