#include<bits/stdc++.h> 
using namespace std;
const int M = 123456;
struct Edge{
	int to,val;
	Edge(int to=0,int val=0):to(to),val(val){}
}edge[M];
int size;
vector<int> G[M];
int n,m;

int addedge(int A,int B,int C){
	
	edge[++size]=Edge(B,C);
	G[A].push_back(size);
	return 0;
}

int dist[M],vis[M],inq[M];
queue<int> q;
int spfa(){
	while(!q.empty()) q.pop();
	for(int i=0;i<=n;i++) vis[i]=0,inq[i]=0;
	q.push(0);
	inq[0]=1;
	while(!q.empty()){
		int from=q.front();
		q.pop();
		inq[from]=0;
		vis[from]++;
		if(vis[from]>20001) return 0;
		for(int i=0;i<G[from].size();i++){
			int to=edge[G[from][i]].to;
		//	if(edge[G[from][i]].val)printf("%d %d %d\n",from,to,edge[G[from][i]].val);
			if(dist[to]<dist[from]+edge[G[from][i]].val){
				dist[to]=dist[from]+edge[G[from][i]].val;
				if(!inq[to]){
					q.push(to);
					inq[to]=1;
				}
			}
		}
	}
	return 1;
}

int main(){
	freopen("A.in","r",stdin);
	int K;
	cin>>n>>K;
	for(int i=0;i<=20001;i++){
		G[i].clear();
	
		dist[i]=-12345678;
	}for(int i=0;i<=20001;i++){
		addedge(i,i+1,0);
		addedge(i+1,i,-1);
	} 
	dist[0]=0;
	for(int i=1;i<=n;i++){
		int A,B;
		cin>>A>>B;
		if(B<A) swap(A,B);
		A+=10001,B+=10001;
		
		if(B-A>=K-1){
			addedge(A,B,K);
		}
		else {
			addedge(A,B,B-A);
			addedge(B,A,A-B);
		}
	}
		 
	spfa();
	printf("%d\n",dist[20001]-dist[0]);
	for(int i=-15;i<=21;i++){
		printf("%d %d\n",i,dist[i+10001]);
	} 
	for(int i=1;i<=20001;i++){
		//printf("%d\n",dist[i]);
		if(dist[i-1]+1==dist[i]){
			printf("%d\n",i-10001);
		}
	}
	return 0;
}
