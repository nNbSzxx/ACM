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

long long ans[M];//ans[i]�������lca(x,y)=i�Ĵ𰸣�����������һ����i�� 
int work(int num,int sz,int length){
	if(sz<=1){ans[num]=0;return 0;}
	d[0]=0;
	dfs(num,0,0);
	//��һ��dfs �ҳ�ÿ��������ϴ�ѡȡ�ķ��εĵ�ľ��� 
	int cc=0;
	int t2=sz;
	sort(1+d,1+d+sz);
	for(int i=1;i<=sz;i++){
		while(t2&&d[t2]+d[i]>m-length){ 
			//����ڵ�ǰ���ϵ�x,y ��d[x]+d[y]<=m-(f[num]��num��Ȩֵ)*2,
			//��ô˵����ͳ��f[num]��ʱ������Ҳ����㣨x,y��������Ҫ��ȥ 
			t2--;	
			if(!t2) break;
		}
		cc+=t2;
		if(d[i]*2<=m-length) cc--;
	}
	cc/=2; 
	sum=sz;K=0;
	find_point(num,num,0);
	//�ҵ��������Ľ����и� ������֤�ϸ� log �� 
	vis[K]=1;
	num=K;
	d[0]=0; 
	dfs(num,0,0);
	//�ڶ���dfs �ҳ�ÿ����������ѡȡ�ķ��εĵ�ľ���
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
		if(d[i]*2<=m) ans[num]--;//�Լ����Լ����ܹ���һ�� 
	}
	ans[num]/=2;//����� 
	for(int j=0;j<G[num].size();j++){
		int to=G[num][j].to;
		if(vis[to]) continue;
		ans[num]=ans[num]-work(to,s[to],G[num][j].val*2);; 
	}
	vis[num]=0;
	return cc;//ccͳ�Ƶ����п��ܶԸõ㸸�׽������ظ��Ĵ� 
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
