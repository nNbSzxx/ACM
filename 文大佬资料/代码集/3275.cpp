
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<vector>

using namespace std;
const int M = 1550;

vector<int> G[M],G2[M];
//用邻接表加速floyd
//用G[M]记录大于关系，G2[M]小宇关系 
bool a[M][M]; 

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		swap(x,y);
		a[x][y]=1;
		G[x].push_back(y); 
		G2[y].push_back(x);
	}
	for(int k=1;k<=n;k++){
		for(int i=0;i<G[k].size();i++){
			for(int j=0;j<G2[k].size();j++){
				int to=G[k][i],from=G2[k][j];
				if(a[from][to]) continue;
				a[from][to]=1;
				G[from].push_back(to);
				G2[to].push_back(from);
			} 
		}
	}
	/*printf("\n");
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}*/
	int cnt=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i][j]) cnt++;
		}
	}
	printf("%d\n",n*(n-1)/2-cnt);
	return 0;
} 
