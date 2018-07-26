#include <cstring>
#include <cstdio>
using namespace std;

const int MAX = 500005;
int cnt, head[MAX];
int left[MAX],right[MAX],now;
int father[MAX];
int n, q;

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
void dfs(int x, int fa)
{
    father[x] = fa;
	left[x] = ++ now;
	for (int i = head[x]; i; i = edge[i].nt) {
        if (edge[i].v != fa)
            dfs(edge[i].v);
	}
	right[x] = now;
	return ;
}
int main()
{

    init();
    scanf("%d",&n);
    build(1,1,n);
    for (int i = 1; i <= n - 1; i ++) {
        scanf("%d%d",&v,&u);
        add(u, v);
        add(v, u);
    }
    dfs(1);

    scanf("%d",&q);
    int x, y;
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d",&x, &y);
        if (x == ) {
            scanf("%d",&x);
            printf("%d\n",query(1,left[x]));
        } else if (x == ) {
            scanf("%d%d",&x,&y);
            modify(1,left[x],right[x],y);
        }
    }

	return 0;
}
