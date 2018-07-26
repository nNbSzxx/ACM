#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<queue>
using namespace std;
const int M = 1234;
double a[M][M];

int st[M];
int prin(int sz){
	for(int i=1;i<=sz;i++){
			for(int j=1;j<=sz+1;j++){
				printf("%4.1lf ",a[i][j]);
			}
			printf("\n");
		}
		printf("\n\n");
		return 0;
}
int gauss(int sz){
	for(int i=1;i<=sz;i++){
		int r=i;
		for(int k=i+1;k<=sz;k++){
			if(fabs(a[k][i])>fabs(a[r][i])) r=k;
		}
		for(int j=1;j<=sz+1;j++){
			swap(a[i][j],a[r][j]);
		}
		for(int k=i+1;k<=sz;k++){
			double kf=a[k][i]/a[i][i];
			for(int j=i;j<=sz+1;j++){
				a[k][j]-=kf*a[i][j];
			}
		} 
	}
	for(int i=sz;i>=1;i--){
		for(int k=i+1;k<=sz;k++){
			a[i][sz+1]-=a[k][sz+1]*a[i][k];
		}
		a[i][sz+1]/=a[i][i];
	}
	return 0;
}


double eps=1e-9;
double p[M];
bool vis[M];
int dist[M];

int n,m,y,x,d;
int idx(int num,int step){
	return (num+step)%(2*n);
} 
queue<int>q;

int bfs(int start){
	q.push(start);
	vis[start]=1;
	while(!q.empty()){
		int from=q.front();
		dist[from]=1;
		q.pop();
		if(from==y||from==2*n-y) continue;
 		for(int i=1;i<=m;i++){
			if(fabs(p[i])>eps){
				int to=idx(from,i);
				if(vis[to]) continue;
				vis[to]=1;
				q.push(to);
			}
		}
	}
	return 0;
}

int init(){
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			a[i][j]=0.0;
		}
		dist[i]=0;
		vis[i]=0;
		st[i]=0;
	}
	return 0;
}

int main(){
	freopen("A.in","r",stdin);
	//freopen("A.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		memset(dist,0,sizeof(dist));
		cin>>n>>m>>y>>x>>d;
		init();
		n--;
		for(int i=1;i<=m;i++){
			cin>>p[i];
			p[i]/=100.0;
		}
		if(x==y){
			printf("0.00\n");
			continue;
		}
		bfs(d==0?x:2*n-x);
		if(dist[y]==0&&dist[2*n-y]==0){
			printf("Impossible !\n");
			continue;
		}
		int sz=0;
		for(int i=0;i<2*n;i++){
			if(dist[i]){
				st[i]=++sz;	
			}
			else st[i]=0;
		}
		for(int i=0;i<2*n;i++){
			if(!dist[i]) continue;
			a[st[i]][st[i]]=-1.0;
			if(i==y||i==2*n-y) continue;
			for(int j=1;j<=m;j++){
				if(fabs(p[j])<eps) continue;
				int to=st[idx(i,j)];
				a[st[i]][to]+=p[j];
				a[st[i]][sz+1]-=p[j]*j;
			}
		}
		gauss(sz);
		int num=(d==0?st[x]:st[2*n-x]);
		printf("%.2lf\n",a[num][sz+1]);
	}
	return 0;
}
