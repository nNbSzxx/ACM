#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;
const int M= 12345;
struct Edge{
	int to,val;
	Edge(int to=0,int val=0) : to(to),val(val){}
};
vector<Edge> G[M];
int vis[M];
int s[M];
int d[M];
int dfs(int num,int dist,int fa){
	s[num]=1;
	d[++d[0]]=dist;
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(vis[to]||to==fa) continue;
		s[num]+=dfs(to,dist+G[num][i].val,num);
	}
	return s[num];
}
int K,sum;
int n,m;
int find_point(int num,int root,int fa){
	int mx=s[root]-s[num];
	if(mx>=sum) return 0;
	for(int i=0;i<G[num].size();i++){
		int to=G[num][i].to;
		if(vis[to]||to==fa) continue;
		mx=max(mx,s[to]);
	}
	if(mx<sum){
		K=num;
		sum=mx;
	}
	for(int i=0;i<G[num].size();i++){	
		int to=G[num][i].to;
		if(vis[to]||to==fa) continue;
		find_point(to,root,num);
	}
	return 0;
} 

long long ans[M];//ans[i]保存的是lca(x,y)=i的答案，即两点连线一定过i点 
int work(int num,int sz,int length){
	if(sz<=1){ans[num]=0;return 0;}
	d[0]=0;
	dfs(num,0,0);
	//第一次dfs 找出每个点对于上次选取的分治的点的距离 
	int cc=0;
	int t2=sz;
	sort(1+d,1+d+sz);
	for(int i=1;i<=sz;i++){
		while(t2&&d[t2]+d[i]>m-length){ 
			//如果在当前集合的x,y 有d[x]+d[y]<=m-(f[num]到num的权值)*2,
			//那么说明在统计f[num]的时候我们也会计算（x,y），所以要减去 
			t2--;	
			if(!t2) break;
		}
		cc+=t2;
		if(d[i]*2<=m-length) cc--;
	}
	cc/=2; 
	sum=sz;K=0;
	find_point(num,num,0);
	//找到树的重心进行切割 这样保证严格 log 层 
	vis[K]=1;
	num=K;
	d[0]=0; 
	dfs(num,0,0);
	//第二次dfs 找出每个点对于这次选取的分治的点的距离
	int t=sz;
	sort(1+d,1+d+sz);

	ans[num]=0;
	for(int i=1;i<=sz;i++){
		if(d[i]>m) break;
		while(t&&d[t]+d[i]>m){
			t--;	
			if(!t) break;
		}
		ans[num]+=t;
		if(d[i]*2<=m) ans[num]--;//自己和自己不能构成一对 
	}
	ans[num]/=2;//有序对 
	for(int j=0;j<G[num].size();j++){
		int to=G[num][j].to;
		if(vis[to]) continue;
		ans[num]=ans[num]-work(to,s[to],G[num][j].val*2);; 
	}
	vis[num]=0;
	return cc;//cc统计的是有可能对该点父亲结点造成重复的答案 
}


int main(){
	freopen("A.in","r",stdin);
	while(1){
		cin>>n>>m;
		if(n+m==0) break;
		for(int i=1;i<=n;i++){
			G[i].clear();
			vis[i]=0;
		}
		for(int i=1;i<n;i++){
			int x,y,z;
			cin>>x>>y>>z;
			G[x].push_back(Edge(y,z));
			G[y].push_back(Edge(x,z));
		}
		work(1,n,0);
		long long Ans=0;
		for(int i=1;i<=n;i++) Ans+=ans[i];
		printf("%lld\n",Ans);
	}
	return 0;
} 
