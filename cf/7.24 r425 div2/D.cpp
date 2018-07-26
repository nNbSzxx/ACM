#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e5 + 10;
struct edge{
	int v, nt;
} e[MAX * 2];
int head[MAX], cnt;
int n, q;
struct node{
	int a[3];
	node(int b, int c, int d) {
		a[0] = b;
		a[1] = c;
		a[2] = d;
		sort(a, a + 3);
	}
	bool operator== (const node& rhs) const {
		return (a[0] == rhs.a[0] && a[1] == rhs.a[1] && a[2] == rhs.a[2]);
	}
	bool operator< (const node& rhs) const {
		return (a[0] < rhs.a[0] || a[0] == rhs.a[0] && a[1] < rhs.a[1] || a[0] == rhs.a[0] && a[1] == rhs.a[1] && a[2] < rhs.a[2]);
	}
};
map<node, int> mp;
void add(int u, int v)
{
	e[cnt].v = v;
	e[cnt].nt = head[u];
	head[u] = cnt ++;
	return ;
}
 
int father[MAX];
int dis[MAX];
int dep[MAX];
void dfs(int u, int fa, int deep){
    father[u]= fa;
    dep[u]= deep;
    for(int i = head[u]; i; i = e[i].nt){
        int v = e[i].v;
        if(v == fa) continue; //

        dis[v]= dis[u] + 1;
        dfs(v, u, deep + 1);
    }
}

int p[MAX][30];
void Init_LCA(){
    for(int j=0; (1<<j)<=n; ++j)
        for(int i=1; i<=n; ++i)
            p[i][j]= -1;
    for(int i=1; i<=n; ++i) p[i][0] = father[i];
    for(int j=1; (1<<j)<=n; ++j)
        for(int i=1; i<=n; ++i)
            if( p[i][j-1] != -1 )
                p[i][j]= p[ p[i][j-1] ][ j-1 ];
}

int LCA(int x, int y) {
    if( dep[x] < dep[y] ) swap(x, y);
    int i, lg;
    for(lg = 0; (1 << lg) <= dep[x]; ++ lg);
    -- lg;
    for(i = lg; i >= 0; -- i)
        if(dep[x] - (1 << i) >= dep[y] )
            x = p[x][i];
    if(x == y) return x;
   
    for(i = lg; i >= 0; -- i)
        if( p[x][i] != -1 && p[x][i] != p[y][i] )
            x= p[x][i], y= p[y][i];
    return father[x];
}
 
int getlen(int x, int y)
{
	int l = LCA(x, y);
	return dis[x] + dis[y] - 2 * dis[l];
}

int main()
{
	scanf("%d%d", &n, &q);
	cnt = 1;
	int u, v;
	for (int i = 2; i <= n; i ++) {
		scanf("%d", &v);
		add(i, v);
		add(v, i);
	}
	dis[1] = 0;
	dfs(1, -1, 0);
	int x, y, z, ans;
	Init_LCA();
	while (q --) {
		scanf("%d%d%d", &x, &y, &z);
		node nn = node(x, y, z);
		if (mp.count(nn)) {
			cout << mp[nn] << endl;
			continue;
		}
		ans = 0;
		int xy = getlen(x, y);
		int xz = getlen(x, z);
		int yz = getlen(y, z);
		ans = max(ans, (xy + xz - yz) / 2 + 1);
		ans = max(ans, (xy + yz - xz) / 2 + 1);
		ans = max(ans, (xz + yz - xy) / 2 + 1);
		printf("%d\n", ans);
		mp[nn] = ans;
	}
	return 0;
}
