/**
 * 2-sat 是可满足性问题，化成合取范式之后，每个子句中文字个数不超过2
 * 对一个子句(a V b)，若a为假则b必须为真，若b为假则a必须为真
 * 即!a为真，b必须为真，!b为真，a必须为真
 * 如此，一个文字分为两个节点a与!a，可以连两条有向边，一条是!a -> b，一条是!b -> a
 * 若a !a出现在同一强连通分量中，则一定无解
 * 否则有解，看a !a所处的强连通分量的拓扑序，若!a在a之前，则a为真，否则a为假
 *
 * 当面对一个点只有两种状态，两种状态非此即彼的时候，可以考虑2-sat
 */
#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int MAXN = 2e3 + 10;
const int MAXM = 4e6 + 10;

struct edge {
    int v, nt;
} e[MAXM];
int head[MAXN], cnte;
int dfn[MAXN], low[MAXN], idx, color[MAXN], cntc;
stack<int> s;

// tsort
queue<int> q;
int head2[MAXN], cnte2;
edge e2[MAXM];
int indeg[MAXN], corder[MAXN];

int n;
int beg[MAXN], ed[MAXN], len[MAXN];


void add(int h[MAXN], edge ed[MAXM], int &cnt, int u, int v)
{
    ++ cnt;
    ed[cnt].v = v;
    ed[cnt].nt = h[u];
    h[u] = cnt;
}

bool overlap(int x1, int y1, int x2, int y2)
{
    return (x2 < x1 && x1 < y2) ||
           (x2 < y1 && y1 < y2) ||
           (x1 < x2 && x2 < y1) ||
           (x1 < y2 && y2 < y1) ||
           (x1 == x2) ||
           (y1 == y2);
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ idx;
    s.push(u);
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (!dfn[v]) {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        } else if (!color[v]) {
            low[u] = min(low[u], dfn[v]);
        }
    }
    if (low[u] == dfn[u]) {
        ++ cntc;
        while (true) {
            int now = s.top();
            s.pop();
            color[now] = cntc;
            if (now == u) {
                break;
            }
        }
    }
}

void tsort()
{
    int ord = 0;
    for (int i = 1; i <= cntc; i ++) {
        if (indeg[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        corder[u] = ++ ord;
        for (int i = head2[u]; i; i = e2[i].nt) {
            int v = e2[i].v;
            indeg[v] --;
            if (!indeg[v]) {
                q.push(v);
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &n)) {
        int h, m;
        for (int i = 0; i < n; i ++) {
            scanf("%d:%d", &h, &m);
            beg[i] = 60 * h + m;
            scanf("%d:%d", &h, &m);
            ed[i] = 60 * h + m;
            scanf("%d", &len[i]);
        }
        cnte = 0;
        memset(head, 0, sizeof head);
        // 拆点，分别为i, i + n
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (overlap(beg[i], beg[i] + len[i], beg[j], beg[j] + len[j])) {
                    // !(a && b) == !a V !b
                    add(head, e, cnte, i, j + n);
                    add(head, e, cnte, j, i + n);
                }
                if (overlap(beg[i], beg[i] + len[i], ed[j] - len[j], ed[j])) {
                    // !(a && !b) == !a V b
                    add(head, e, cnte, i, j);
                    add(head, e, cnte, j + n, i + n);
                }
                if (overlap(ed[i] - len[i], ed[i], beg[j], beg[j] + len[j])) {
                    // !(!a && b) == a V !b
                    add(head, e, cnte, i + n, j + n);
                    add(head, e, cnte, j, i);
                }
                if (overlap(ed[i] - len[i], ed[i], ed[j] - len[j], ed[j])) {
                    // !(!a && !b) == a V b
                    add(head, e, cnte, i + n, j);
                    add(head, e, cnte, j + n, i);
                }
            }
        }
        // tarjan
        memset(dfn, 0, sizeof dfn);
        idx = 0;
        memset(color, 0, sizeof color);
        cntc = 0;
        for (int i = 0; i < 2 * n; i ++) {
            if (!dfn[i]) {
                tarjan(i);
            }
        }
        int ok = true;
        for (int i = 0; i < n; i ++) {
            if (color[i] == color[i + n]) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            puts("NO");
        } else {
            puts("YES");
            memset(indeg, 0, sizeof indeg);
            memset(head2, 0, sizeof head2);
            cnte2 = 0;
            for (int u = 0; u < 2 * n; u ++) {
                for (int i = head[u]; i; i = e[i].nt) {
                    if (color[u] != color[e[i].v]) {
                        indeg[color[e[i].v]] ++;
                        add(head2, e2, cnte2, color[u], color[e[i].v]);
                    }
                }
            }
            // tsort
            tsort();
            for (int i = 0; i < n; i ++) {
                int b, e;
                if (corder[color[i]] > corder[color[i + n]]) {
                    // !a在a之前，a为真
                    b = beg[i];
                    e = beg[i] + len[i];
                } else {
                    // !a在a之后，a为假
                    b = ed[i] - len[i];
                    e = ed[i];
                }
                printf("%02d:%02d %02d:%02d\n", b / 60, b % 60, e / 60, e % 60);
            }
        }
    }
    return 0;
}
