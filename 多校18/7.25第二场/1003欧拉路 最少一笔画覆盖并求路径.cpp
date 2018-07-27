#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
using namespace std;
const int MAX = 1e5 + 10;
struct E {
    int v, nt, id, vis;
} e[MAX << 2];
int head[MAX], cnte;
int father[MAX], size[MAX], sumodd[MAX], tmp[MAX << 2], MAXIdx[MAX << 2];
int degree[MAX];
int n, m, ans;

/*
struct DE {
    int u, v, id;
    DE(int uu, int vv, int idd): u(uu), v(vv), id(idd) {}
};
*/
stack<int> s;
int oddcnt, lastodd;

queue<int> q;
vector<int> outp;

void init()
{
    cnte = 0;
    memset(head, -1, sizeof head);
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
        size[i] = 1;
    }
    memset(degree, 0, sizeof degree);
    memset(sumodd, 0, sizeof sumodd);
    ans = 0;
}

int find(int x)
{
    while (x != father[x]) {
        father[x] = father[father[x]];
        x = father[x];
    }
    return x;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x > y) {
        father[y] = x;
        size[x] += size[y];
    } else if (x < y) {
        father[x] = y;
        size[y] += size[x];
    }

}

void add(int u, int v, int id)
{
    e[cnte].v = v;
    e[cnte].id = id;
    e[cnte].vis = 0;
    e[cnte].nt = head[u];
    head[u] = cnte;
    ++ cnte;
}

void dfs(int x)
{
    if (degree[x]) {
        if (oddcnt == 0) {
            ++ oddcnt;
            lastodd = x;
            degree[x] ^= 1;
        } else {
            //if (x != lastodd) {
                oddcnt = 0;
                degree[x] ^= 1;
                //degree[lastodd] ^= 1;
                dfs(lastodd);
                s.push(MAX);
            //}
        }
    }
    for (int i = head[x]; ~i; i = e[i].nt) {
        if (!e[i].vis) {
            e[i].vis = 1;
            e[i ^ 1].vis = 1;
            dfs(e[i].v);
            s.push(e[i].id);
        }
    }
}

int main()
{
    //freopen("1003.in", "r", stdin);
    //freopen("1003out.out", "w", stdout);
    while (~scanf("%d%d", &n, &m)) {
        init();
        for (int i = 1; i <= m; i ++) {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v, i);
            add(v, u, -i);
            merge(u, v);
            degree[u] ^= 1;
            degree[v] ^= 1;
        }

        for (int i = 1; i <= n; i ++) {
            if (degree[i] & 1) {
                int x = find(i);
                sumodd[x] += 1;
            }
        }
        for (int i = 1; i <= n; i ++) {
            int x = find(i);
            if (i == x && size[x] != 1) {
                ans += max(1, sumodd[x] / 2);
            }
        }
        printf("%d\n", ans);

        for (int i = 1; i <= n; i ++) {
            if (i == find(i) && size[i] != 1) {
                oddcnt = 0;
                dfs(i);
                /*
                outp.clear();
                int MAXCnt = 0;
                int tmpCnt = 0;
                while (!s.empty()) {
                    tmp[tmpCnt++] = s.top();
                    s.pop();
                }
                if (!tmpCnt) continue;
                for (int j = 0; j < tmpCnt; ++j)
                    if (tmp[j] == MAX) MAXIdx[MAXCnt++] = j;
                if (!MAXCnt) {
                    printf("%d", tmpCnt);
                    for (int j = 0; j < tmpCnt; ++j) printf(" %d", tmp[j]);
                    puts("");
                }
                else {
                    MAXIdx[MAXCnt] = MAXIdx[0];
                    for (int j = 0; j < MAXCnt; ++j) {
                        outp.clear();
                        int k = (MAXIdx[j] + 1) % tmpCnt;
                        while (k != MAXIdx[j + 1]) {
                            outp.push_back(tmp[k]);
                            k = (k + 1) % tmpCnt;
                        }
                        if (!outp.size()) continue;
                        printf("%d", (int)outp.size());
                        for (int id : outp) printf(" %d", id);
                        puts("");
                    }
                }
                */

                int maxcnt = 0;
                while (!s.empty()) {
                    int id = s.top();
                    if (id == MAX) {
                        if (maxcnt && outp.size()) {
                            printf("%d ", outp.size());
                            for (int i = 0; i < outp.size(); i ++) {
                                printf(i==(outp.size()-1)?"%d\n":"%d ", outp[i]);
                            }
                            outp.clear();
                        }
                        maxcnt ++;
                    } else {
                        if (maxcnt == 0) {
                            q.push(id);
                        } else {
                            outp.push_back(id);
                        }
                    }
                    s.pop();
                }
                int ts = q.size() + outp.size();
                if (ts) {
                    printf("%d ", ts);
                    for (int i = 0; i < outp.size(); i ++) {
                        if (i == outp.size() - 1) {
                            if (i == ts - 1) {
                                printf("%d\n", outp[i]);
                            } else {
                                printf("%d ", outp[i]);
                            }
                        } else {
                            printf("%d ", outp[i]);
                        }
                    }
                    outp.clear();
                    while (!q.empty()) {
                        printf("%d", q.front());
                        q.pop();
                        if (!q.empty()) {
                            putchar(' ');
                        } else {
                            puts("");
                        }
                    }
                }

            }
        }
    }
    return 0;
}
