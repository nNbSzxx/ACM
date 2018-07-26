#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int M = 12345;
struct Edge{
	int to,val,key;//�ߵ���һ����㣬Ȩֵ����� 
	Edge(int to=0,int val=0,int key=0):to(to),val(val),key(key){} 
};
int fa[M][15];
vector<Edge>G[M];
int s[M];//�������ĸ��� 
int top[M];//������ͷ��� 
int e[M];//�����߶����ж�Ӧ�ı�� 
int pos[M];//�����߶����ж�Ӧ�ı�� 
int deep[M];//������ 
struct Tree{
	int vala,valb;//vala�����ֵ,valb����Сֵ 
	int tag;
}tree[M*4];
int n; 
int build(int num,int l,int r){
	tree[num].vala=-M*M;
	tree[num].valb=M*M;
	tree[num].tag=0;
	if(l==r) return 0;
	int mid=(l+r)>>1;
	build(num<<1,l,mid);
	build(num<<1|1,mid+1,r);		
	return 0;
}


int pushup(int num){
	tree[num].vala=max(tree[num<<1].vala,tree[num<<1|1].vala);
	tree[num].valb=min(tree[num<<1].valb,tree[num<<1|1].valb);
	return 0;
}

int change(int &x,int &y){
	int tmp=x;x=-y;y=-tmp;
	return 0;
}

int pushdown(int num,int l,int r){
	if(l==r||tree[num].tag==0) return 0;
	tree[num].tag=0;
	int lson=num<<1,rson=num<<1|1;
	tree[lson].tag^=1;tree[rson].tag^=1;
	change(tree[lson].vala,tree[lson].valb);
	change(tree[rson].vala,tree[rson].valb);
	return 0;
}	

int query(int num,int l,int r,int left,int right){
	pushdown(num,l,r);
	if(l>=left&&r<=right){
		return tree[num].vala;
	}
	int mid=(l+r)>>1;
	int ans=-M*M;
	if(left<=mid) ans=max(ans,query(num<<1,l,mid,left,right));
	if(right>mid) ans=max(ans,query(num<<1|1,mid+1,r,left,right));
	return ans;
}

int modefy(int num,int l,int r,int K,int val){//�����޸�Kֵ 
	if(l==r){
		tree[num].vala=val;
		tree[num].valb=val;
		return 0;
	}
	pushdown(num,l,r);
	int mid=(l+r)>>1;
	if(K<=mid) modefy(num<<1,l,mid,K,val);
	else modefy(num<<1|1,mid+1,r,K,val);
	pushup(num);
	return 0; 
}

int rever(int num,int l,int r,int left,int right){//left �� right����ȡ�� 
	
	if(l>=left&&r<=right){
		tree[num].tag^=1;
		change(tree[num].vala,tree[num].valb);
		return 0;
	}
	pushdown(num,l,r);
	int mid=(l+r)>>1;
	if(left<=mid) rever(num<<1,l,mid,left,right);
	if(right>mid) rever(num<<1|1,mid+1,r,left,right);
	pushup(num);
	return 0;
}

int dfs1(int num){
	s[num]=1;
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(to!=fa[num][0]){
			fa[to][0]=num;
			deep[to]=deep[num]+1;
			s[num]+=dfs1(to);
		}
	}
	return s[num];
}

int sz=0;
int dfs2(int num,int chain){
	top[num]=chain;
	pos[num]=++sz;
	int K=0;//���ض��� 
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(to!=fa[num][0]){
			if(s[to]>s[K]) K=to;
		}
		else {
			e[G[num][i].key]=pos[num]; 
			modefy(1,1,n,pos[num],G[num][i].val);
		//���ڴ�ͳ�������ʷֶ��ǵ�Ȩ�������Ǳ�Ȩ��
		//���Խ���Ȩ����deep�ϴ�ĵ㣬��ѯ��ʱ����Ҫע�� 
		}
	} 
	if(!K) return 0;
	dfs2(K,chain);//���ȵݹ��ض��ӣ�ʹ������ 
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(to!=fa[num][0]&&to!=K){
			dfs2(to,to);
		}
	}
	return 0;
}

int solve1(int num,int father){
	int mx=-M*M;
	while(top[num]!=top[father]){
		mx=max(mx,query(1,1,n,pos[top[num]],pos[num]));
		num=fa[top[num]][0];
	}
	if(pos[father]+1<=pos[num])
		mx=max(mx,query(1,1,n,pos[father]+1,pos[num]));
		//���ڴ�ͳ�������ʷֶ��ǵ�Ȩ�������Ǳ�Ȩ��
		//����һ���ߵ������㣬Ҫ��ѯdeep�ϴ�ĵ㣬���� pos[father]+1
	return mx;
}
int solve2(int num,int father){
	while(top[num]!=top[father]){
		rever(1,1,n,pos[top[num]],pos[num]);
		num=fa[top[num]][0];
	}
	if(pos[father]+1<=pos[num])
		rever(1,1,n,pos[father]+1,pos[num]);
	return 0;
}

int bin[15];//���汶��ֵ 
int lca(int x,int y){
	if(deep[x]<deep[y])swap(x,y);
	int t=deep[x]-deep[y];
	for(int i=0;i<=13;i++)
		if(t&bin[i])x=fa[x][i];
	for(int i=13;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
			x=fa[x][i],y=fa[y][i];
	if(x==y)return x;
	return fa[x][0];
}


int addedge(int u,int v,int w,int k){
	G[u].push_back(Edge(v,w,k));
	G[v].push_back(Edge(u,w,k));
	return 0;
}

inline int read(){
	int tmp=0,flag=1;char ch=getchar();
	while(ch>'9'||ch<'0'){if(ch=='-')flag=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){tmp=tmp*10+ch-'0';ch=getchar();}
	return tmp*flag;
}
int main(){
	freopen("test.in","r",stdin); 
	bin[0]=1;
	for(int i=1;i<15;i++)bin[i]=bin[i-1]<<1;
	int T;
	cin>>T;
	while(T--){
		sz=0;
		for(int i=1;i<=n;i++) G[i].clear();
		memset(fa,0,sizeof(fa));
		n=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read(),w=read();
			addedge(u,v,w,i);
		}
		fa[1][0]=0;
		build(1,1,n);
		dfs1(1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=13;j++)
				fa[i][j]=fa[fa[i][j-1]][j-1];
		dfs2(1,1);
		char ch[10];
		while(scanf("%s",ch+1)){
			if(ch[1]=='D')break;
			int x=read(),y=read();
			if(ch[1]=='Q'){
				int father=lca(x,y);
				printf("%d\n",max(solve1(x,father),solve1(y,father)));
			}
			if(ch[1]=='C'){
				modefy(1,1,n,e[x],y);
			}
			if(ch[1]=='N'){
				int father=lca(x,y);
				solve2(x,father);solve2(y,father);
			}
		}
	}
	return 0;
}
