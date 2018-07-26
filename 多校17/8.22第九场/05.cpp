#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1010;
const int MAXM = 6010;
vector<int> g[MAXN], mp[MAXN];
stack<int> s;
int n, m, dfn[MAXN], low[MAXN], cnt, flag[MAXN], clr, belong[MAXN];
int degree[MAXN];

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
            low[x] = min(low[x], dfn[v]);
        }
    }
    int v;
    if (dfn[x] == low[x]) {
        ++ clr;
        do {
            v = s.top(); s.pop();
            flag[v] = 0;
            belong[v] = clr;
        } while (x != v);
    }
    return ;
}

void build()
{
    for (int i = 1; i <= clr; i ++) {
        mp[i].clear();
    }
    for (int i = 1; i <= n; i ++) {
        for (int j = 0; j < g[i].size(); j ++) {
            int v = g[i][j];
            if (belong[i] != belong[v]) {
                mp[belong[i]].push_back(belong[v]);
                degree[belong[v]] ++;
            }
        }
    }
}

bool tsort()
{
    while (!s.empty()) s.pop();
    for (int i = 1; i <= clr; i ++) {
        if (!degree[i]) {
            s.push(i);
        }
    }
    while (!s.empty()) {
        if (s.size() > 1) {
            return false;
        }
        int now = s.top(); s.pop();
        for (int i = 0; i < mp[now].size(); i ++) {
            int v = mp[now][i];
            degree[v] --;
            if (!degree[v]) {
                s.push(v);
            }
        }
    }
    return true;
}

int main()
{
    //freopen("1005.in", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(dfn, 0, sizeof dfn);
        memset(low, 0, sizeof low);
        memset(flag, 0, sizeof flag);
        memset(belong, 0, sizeof belong);
        memset(degree, 0, sizeof degree);
        cnt = clr = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) g[i].clear();

        int u, v;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d", &u, &v);
            g[u].push_back(v);
        }

        for (int i = 1; i <= n; i ++) {
            if (!dfn[i]) {
                while (!s.empty()) {
                    s.pop();
                }
                tarjan(i);
            }
        }

        build();
        if (tsort()) {
            puts("I love you my love and our love save us!");
            //cout << clr << endl;
        } else {
            puts("Light my fire!");
            //cout << clr << endl;
        }
    }
    return 0;
}
