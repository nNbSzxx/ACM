#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 50005;
int cnt, head[MAX];
int vis[MAX],left[MAX],right[MAX],now;

struct Tree {
	int tag;
	int l,r;
} t[MAX * 4];
struct Node {
	int v,nt;
} edge[MAX];

void init(void)
{
	memset(left,0,sizeof(left));
	memset(right,0,sizeof(right));
	memset(vis,0,sizeof(vis));
	memset(t,0,sizeof(t));
	memset(edge,0,sizeof(edge));
	memset(head,0,sizeof(head));
	cnt = 1;
	now = 0;
}
void add(int u, int v)
{
	edge[cnt].v = v;
	edge[cnt].nt = head[u];
	head[u] = cnt;
	++ cnt;
	return ; 
}
void pushdown(int x)
{
	if (t[x].l == t[x].r || t[x].tag == -1) return ;
	t[x*2].tag = t[x*2+1].tag = t[x].tag;
	t[x].tag = -1;
	return ;
}
void build (int x, int l, int r)
{
	t[x].tag = -1;
	t[x].l = l; t[x].r = r;
	if (l == r) {
		return ;
	}
	int mid = (l+r) >> 1;
	build(2*x, l, mid);
	build(2*x+1,mid+1,r);
	return ;
}
void modify(int x,int l, int r, int v)
{
	if (l <= t[x].l && t[x].r <= r) {
		t[x].tag = v;
		return ;
	}
	pushdown(x);
	int mid = (t[x].l + t[x].r) >> 1;
	if (l <= mid) modify(x*2,l,r,v);
	if (r > mid) modify(x*2+1,l,r,v);
}
int query(int x, int loc)
{
//	printf("%d %d %d %d\n",x,t[x].l,t[x].r,t[x].sum);
	if (t[x].l == t[x].r) {
		return t[x].tag;
	}
	int mid = (t[x].l + t[x].r ) >> 1;
	pushdown(x);
	if (loc <= mid) return query(x*2,loc);
	else return query(x*2+1,loc);
}
void dfs(int x)
{
	left[x] = ++ now;
	for (int i = head[x]; i; i = edge[i].nt) {
		dfs(edge[i].v);
	}
	right[x] = now;
	return ;
}
int main()
{
	int t,tc = 0;
	scanf("%d",&t);
	while (t --) {
		init();
		int n,m,u,v;
		scanf("%d",&n);
		build(1,1,n);
		for (int i = 1; i <= n - 1; i ++) {
			scanf("%d%d",&v,&u);
			add(u,v);
			vis[v] = 1;
		}
		int root;
		for (int i = 1; i <= n; i ++) {
			if (vis[i] == 0) {
				root = i;
				break;
			}
		}
		dfs(root);
//		printf("\n");
//		for (int i = 1; i <= n; i ++) {
//			printf("%d %d\n",left[i],right[i]);
//		}
		scanf("%d",&m);
		printf("Case #%d:\n",++ tc);
		char c;int x,y;
		for (int i = 1; i <= m; i ++) {
			scanf(" %c",&c);
			if (c == 'C') {
				scanf("%d",&x);
				printf("%d\n",query(1,left[x]));
			} else if (c == 'T') {
				scanf("%d%d",&x,&y);
				modify(1,left[x],right[x],y);
			}
		}
	}
	return 0;
}
