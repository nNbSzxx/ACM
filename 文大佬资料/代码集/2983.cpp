#include<bits/stdc++.h> 
using namespace std;
const int M = 1234567;
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
		if(vis[from]>n) return 0;
		for(int i=0;i<G[from].size();i++){
			int to=edge[G[from][i]].to;
			//printf("%d %d %d\n",from,to,edge[G[from][i]].val);
			if(dist[to]>dist[from]+edge[G[from][i]].val){
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
	//freopen("A.in","r",stdin);
	while(cin>>n>>m){
		size=0;
		for(int i=0;i<=n;i++){
			G[i].clear();
			 dist[i]=12345678;
		}
		dist[0]=0;
		for(int i=1;i<=m;i++){
			int A,B,C=0;
			char t[5];
			cin>>t;
			if(t[0]=='P'){
				cin>>A>>B>>C;
				addedge(B,A,C);
				addedge(A,B,-C);
			}
			if(t[0]=='V'){
				cin>>A>>B;
				addedge(A,B,-1);
			}
		} 
		for (int i = 0; i <= n; i++) addedge(0,i,0); 
		//怕出现若干联通分量的情况 如果从1开始访问有可能访问不到其他联通分量，
		//故强行把所有联通分量通过0号结点连接起来 
		if (!spfa()) cout << "Unreliable" << endl;  
	    else cout << "Reliable" << endl;  
	}
}
