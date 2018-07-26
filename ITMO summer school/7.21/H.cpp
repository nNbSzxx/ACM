#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <set>
using namespace std;
const int MAX = 100010;
const int INF = 0x3f3f3f3f;
struct E {
	int v, w, nt;
}e[MAX * 4];
struct node{
    int v, w;
    node(int vv, int ww) {
        v = vv;
        w = ww;
    }
};
int n, m, head[MAX], cnt, vis[MAX], dis[MAX], len;
vector<int> ans, l;
vector<node> t;
queue<int> q;

void add(int u, int v, int w)
{
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
	return ;
}

void bfs(int s)
{
	while (!q.empty()) {
        q.pop();
	}
	q.push(s);
	memset(vis,0,sizeof(vis));
	vis[s] = 1;
	dis[s] = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (int i = head[now]; i; i = e[i].nt) {
			if (!vis[e[i].v]) {
				q.push(e[i].v);
				dis[e[i].v] = dis[now] + 1;
				vis[e[i].v] = 1;
			}
		}
	}
	return ;
}

void bfs(void)
{
    while (!q.empty()) {
        q.pop();
	}
    memset(vis, 0, sizeof(vis));
    l.clear();
    l.push_back(1);
    int layer = 1;
    while (layer <= len) {
        for (int i = 0; i < l.size(); i ++) {
            if (!vis[l[i]])
                q.push(l[i]), vis[l[i]] = 1;
        }
        l.clear();
        t.clear();
        while (!q.empty()) {
            int now = q.front(); q.pop();
            for (int i = head[now]; i; i = e[i].nt) {
                int v = e[i].v, w = e[i].w;
                if (dis[v] == dis[now] - 1) {
                    t.push_back(node(v, w));
                }
            }
        }
        int w = t[0].w;
        l.push_back(t[0].v);
        for (int i = 1; i < t.size(); i ++) {
            if (t[i].w < w) {
                l.clear();
                w = t[i].w;
                l.push_back(t[i].v);
            } else if (t[i].w == w) {
                l.push_back(t[i].v);
            }
        }
        //cout << layer << " " << w << endl;
        ans.push_back(w);
        ++ layer;
    }

    return ;
}

int main()
{
	while(~scanf("%d%d", &n, &m)) {
        memset(head, 0, sizeof(head));
        memset(dis, 0x3f, sizeof(dis));

        memset(e, 0, sizeof(e));
        ans.clear();
        l.clear();
        t.clear();
        cnt = 1;

        int u, v, w;
        for (int i = 1; i <= m; i ++) {
            scanf("%d%d%d", &u, &v, &w);
            if (u != v) {
                add (u, v, w);
                add (v, u, w);
            }
        }
        bfs(n);
        len = dis[1];
        bfs();
        printf("%d\n", len);
        printf("%d", ans[0]);
        for (int i = 1; i < ans.size(); i ++) {
            printf(" %d", ans[i]);
        }
        puts("");
        /*
        for (int i = 1; i <= n; i ++) {
            cout << dis1[i] << " ";
        }
        cout << endl;
        for (int i  =1; i <= n; i ++) {
            cout << disn[i] << " ";
        }
        cout << endl;
        */

	}

    return 0;
}
