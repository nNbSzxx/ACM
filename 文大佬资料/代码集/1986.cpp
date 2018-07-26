#include<bits/stdc++.h> 
using namespace std; 
const int M = 423456;
struct Edge{
	int to,val;
	Edge(int to=0,int val=0):to(to),val(val){}
};
vector<Edge> G[M];
int fa[M][22];
int dist[M];

int deep[M];
int dfs(int num){
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(to==fa[num][0]) continue;
		fa[to][0]=num;
		dist[to]=dist[num]+G[num][i].val;
		deep[to]=deep[num]+1;
		dfs(to);
	}
	return 0;
}
int bin[22]; 
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=20;i++)
		if(t&bin[i])x=fa[x][i];
	if(x==y)return x; 
	for(int i=20;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}
inline int read(){
	int tmp=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')flag=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){tmp=tmp*10+ch-'0';ch=getchar();}
	return tmp*flag;
}
int main(){
	freopen("data.in","r",stdin);
	bin[0]=1;
	for(int i=1;i<=20;i++) bin[i]=bin[i-1]*2;
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int A,B,C;
		A=read();B=read();C=read();
		G[A].push_back(Edge(B,C));
		G[B].push_back(Edge(A,C)); 
	}
	dist[1]=0;
	deep[1]=1;
	dfs(1);
	
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			fa[i][j]=fa[fa[i][j-1]][j-1];
	int q=read();
	for(int i=1;i<=q;i++){
		//printf("%d\n",i);
		int A,B;
		A=read();B=read();
		int father=lca(A,B);
		//printf("%d %d %d\n",A,B,father);
		printf("%d\n",dist[A]+dist[B]-2*dist[father]); 
	}
	
	return 0;	
}
