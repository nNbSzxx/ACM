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
int father[MAX], size[MAX], sumodd[MAX], tmp[MAX << 2];
int degree[MAX];
int n, m, ans;

stack<int> s;

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

/**
 * dfs找欧拉路，前提是存在欧拉路
 * 如果都是偶点，或者入度等于出度，则从任意一点开始都可以
 * 如果有两个奇点，则需要从其中一个开始dfs
 * 如果有两个点入度不等于出度，这两个点必须其中一个出度比入度大1，另一个入度比出度大1，
 * 从出度比入度大1的点开始
 * 核心是递归返回时把边压入栈中
 * dfs结束后从栈中依次弹出就是路径
 */
void dfs(int x)
{
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

        int lastodd;
        int oddcnt = 0;
        for (int i = 1; i <= n; i ++) {
            if (degree[i] & 1) {
                int x = find(i);
                sumodd[x] += 1;
                if (!oddcnt) {
                    oddcnt ^= 1;
                    lastodd = i;
                } else {
                    oddcnt ^= 1;
                    add(i, lastodd, MAX);
                    add(lastodd, i, MAX);
                }
            }
        }

        /**
         * 一个连通分量需要的一笔画的笔数：
         * 1. 孤立点为0
         * 2. 无奇点为1
         * 3. 否则是奇点数目除以2
         */
        for (int i = 1; i <= n; i ++) {
            int x = find(i);
            if (i == x && size[x] != 1) {
                ans += max(1, sumodd[x] / 2);
            }
        }
        printf("%d\n", ans);

        for (int i = 1; i <= n; i ++) {
            if (i == find(i) && size[i] != 1) {
                dfs(i);


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
