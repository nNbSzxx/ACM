#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>


using namespace std;
const int M = 550;
bool a[M][M];

int main(){
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=m;i++){
		int x,y;
		cin>>x>>y;
		a[x][y]=1;
	}
	
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				a[i][j]=max(a[i][j],a[i][k]&&a[k][j]);
			}
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			if(a[i][j]|a[j][i]) cnt++;
		}
		if(cnt==n-1) ans++;
	}
	printf("%d\n",ans);
	return 0;
} 
