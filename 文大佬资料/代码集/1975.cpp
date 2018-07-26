#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>


using namespace std;
const int M = 550;
bool a[M][M];

int main(){
	int T;
	cin>>T;
	while(T--){
		int n,m;
		
		cin>>n>>m;
		memset(a,0,sizeof(a));
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
			int cnt1=0,cnt2=0;
			for(int j=1;j<=n;j++){
				if(a[i][j]) cnt1++;
				if(a[j][i]) cnt2++;
			}
			if(cnt1>n/2||cnt2>n/2) ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}
