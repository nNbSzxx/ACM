#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <unordered_map>
#define int long long
using namespace std;
const int MAXN = 1000010 * 2;
const int MAXC = 10010 * 2;
const int MAXV = 10010 * 2;
const int INF = 0x3F3F3F3F3f3f3f3f;
class Record {
public:
    string div, base;
    int cost, value;
};
class Edge {
public:
    int v, cost, value, next;
};
class Attribute {
public:
    int cost, value;
    Attribute(int co = 0, int va = 0) : cost(co), value(va) { }
    Attribute operator+(Attribute b) { return Attribute(cost + b.cost, value + b.value); }
};
int V, n, c;
string tmp;
unordered_map<string, int> id;
Record recipes[MAXN];
int indeg[MAXC], h[MAXC], hcnt;
Edge edge[MAXN];
Attribute items[MAXC], ans;
bool vis[MAXC];
int dp[MAXV];
inline void addEdge(int u, int v, int cost, int value) {
    ++hcnt;
    edge[hcnt].v = v;
    edge[hcnt].cost = cost;
    edge[hcnt].value = value;
    edge[hcnt].next = h[u];
    h[u] = hcnt;
    ++indeg[v];
}
Attribute min(Attribute a, Attribute b) {
    return (a.cost < b.cost || (a.cost == b.cost && a.value > b.value)) ? a : b;
}
Attribute dfs(int u) {
    if (vis[u]) return items[u];
    vis[u] = true;
    if (!h[u]) return items[u] = Attribute();
    Attribute ret(INF, INF);
    for (int p = h[u]; p; p = edge[p].next) ret = min(ret, dfs(edge[p].v) + Attribute(edge[p].cost, edge[p].value));
    return items[u] = ret;
}
inline void init() {
    id.clear();
    c = 0;
    for (int i = 1; i <= n; ++i) {
        cin >> recipes[i].div >> recipes[i].base >> tmp >> recipes[i].cost >> recipes[i].value;
        if (id.find(recipes[i].div) == id.end()) id[recipes[i].div] = ++c;
        if (id.find(recipes[i].base) == id.end()) id[recipes[i].base] = ++c;
    }
    memset(indeg, 0, sizeof indeg);
    memset(h, 0, sizeof h);
    hcnt = 0;
    for (int i = 1; i <= n; i ++) addEdge(id[recipes[i].div], id[recipes[i].base], recipes[i].cost, recipes[i].value);
    memset(vis, false, sizeof vis);
    for (int i = 1; i <= c; ++i) dfs(i);
}
inline void DP() {
    memset(dp, 0, sizeof dp);
    for (int i = 1; i <= c; ++i)
        for (int j = V; j >= items[i].cost; --j)
            dp[j] = max(dp[j], dp[j - items[i].cost] + items[i].value);
    ans.value = 0;
    ans.cost = INF;
    for (int j = 0; j <= V; ++j)
        if (dp[j] > ans.value) {
            ans.value = dp[j];
            ans.cost = j;
        }
}
main() {
    //freopen("in.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    while (cin >> V >> n) {
        init();
        DP();
        cout << ans.value << endl << ans.cost << endl;
    }
    return 0;

}
