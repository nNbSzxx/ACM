#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int degree[MAX], n, cnt, head[MAX], k, ans, flag;
struct edge {
    int v, nt;
} e[MAX * 2];

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? '@' : *p1++;
}
int over;
inline int _read() {
    char ch = nc();
    int s = 0;
    while(!(ch >= '0' && ch <= '9')) {
        ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    while(ch >= '0' && ch <= '9') {
        s = s * 10 + ch - 48, ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    return s;
}

void add(int u, int v)
{
    e[cnt].v = v;
    e[cnt].nt = head[u];
    head[u] = cnt ++;
    return ;
}
void init ()
{
    flag = 0;
    cnt = 1;
    ans = 0;
    memset(head, 0, sizeof head);
}
void dfs(int u, int fa)
{
    if (flag) return ;
    degree[u] = 1;
    for (int i = head[u]; i; i = e[i].nt) {
        int v = e[i].v;
        if (v != fa) {
            dfs(v, u);
            if (flag) return ;
            degree[u] += degree[v];
        }
    }
    if (degree[u] >= 2) {
        ++ ans;
        if (ans * 2 >= k) {
            flag = 1;
        }
        if (flag) {
            return ;
        }
        degree[u] = 0;
    }
    return ;
}
int main()
{
    //freopen("08.in", "r", stdin);
    int t;
    t = _read();
    while (t --) {
        init();
        n = _read(); k = _read();
        int a;
        for (int i = 2; i <= n; i ++) {
            a = _read();
            add(a, i);
            add(i, a);
        }
        dfs(1, -1);
        if (ans * 2 >= k) ans = k / 2;
        if (ans * 2 < k) {
            ans += k - ans * 2;
        }
        printf("%d\n", ans);
    }
    return 0;
}
