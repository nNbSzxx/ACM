#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e4 + 10;
vector<int> g[MAX];
stack<int> s;
int n, m, dfn[MAX], low[MAX], flag[MAX], cnt, clr;

void tarjan(int x)
{
    s.push(x);
    flag[x] = 1;
    dfn[x] = low[x] = ++ cnt;
    for (int i = 0; i < g[x].size(); i ++) {
        int v = g[x][i];
        if (!dfn[v]) {
            tarjan(v);
            low[x] = min(low[x], low[v]);
        } else if (flag[v]) {
            low[x] = min(low[x], low[v]);
        }
    }
    if (low[x] == dfn[x]) {
        int v;
        ++ clr;
        do {
            v = s.top(); s.pop();
            flag[v] = 0;
        } while (v != x);
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m), n || m) {
        for (int i = 1; i <= n; i ++) {
            g[i].clear();
        }
        memset(dfn, 0, sizeof dfn);
        memset(flag, 0, sizeof flag);
        memset(low, 0, sizeof low);
        cnt = clr = 0;
        int u, v;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }

        int flag = 0;
        for (int i = 1; i <= n; i ++) {
            if (!dfn[i])
                if (!flag) {
                    while (!s.empty()) {
                        s.pop();
                    }
                    tarjan(i);
                    flag = 1;
                } else {
                    flag = 2;
                    break;
                }
        }
        if (flag == 2) {
            puts("No");
            continue;
        }
        if (clr > 1) {
            puts("No");
        } else {
            puts("Yes");
        }
    }
}
