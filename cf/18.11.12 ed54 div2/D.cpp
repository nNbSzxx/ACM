#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 3e5 + 10;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct edge {
    int v, nt, id;
    long long w;
} e[MAX << 1];
int head[MAX], cnte;

void add(int u, int v, int w, int id)
{
    ++ cnte;
    e[cnte].v = v;
    e[cnte].w = w;
    e[cnte].id = id;
    e[cnte].nt = head[u];
    head[u] = cnte;
}

bool visit[MAX];
long long dis[MAX];
int pre[MAX];
int vise[MAX];
vector<int> keye;
int n, m, k;

struct cmp
{
    bool operator()(int a,int b)
    {
        return dis[a] > dis[b];
    }
};
priority_queue<int, vector<int>, cmp> q;

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    memset(head, 0, sizeof head);
    memset(visit, 0, sizeof visit);
    memset(dis, 0x3f, sizeof dis);
    memset(vise, 0, sizeof vise);
    cnte = 0;
    for (int i = 1;i <= m; i ++) {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == y) continue;
        add(x, y, z, i);
        add(y, x, z, i);
    }

    q.push(1);
    dis[1] = 0;
    pre[1] = 0;
    while (!q.empty()) {
        int u = q.top();
        q.pop();
        if (visit[u]) continue;
        visit[u] = true;
        vise[pre[u]] = 1;
        keye.push_back(pre[u]);
        for (int i = head[u]; i; i = e[i].nt) {
            int v = e[i].v;
            if (!visit[v] && dis[v] > dis[u] + e[i].w) {
                dis[v] = dis[u] + e[i].w;
                pre[v] = e[i].id;
                q.push(v);
            }
        }
    }

    if (k >= n - 1) {
        printf("%d\n", n - 1);
        for (int i = 1; i <= m; i ++) {
            if (vise[i]) {
                printf("%d ", i);
            }
        }
        puts("");
    } else {
        printf("%d\n", k);
        int cnt = 0;
        for (int i = 1; i <= m; i ++) {
            if (cnt == k) {
                break;
            }
            if (vise[i]) {
                ++ cnt;
                printf("%d ", i);
            }

        }
    }
    return 0;
}
