#include<bits/stdc++.h> 
using namespace std;
int s[35],e[35],a[35][35],n;
int gauss(){
	int u,c;
	for(u=1,c=1;u<=n&&c<=n;c++){
		int k=0;
		for(int i=u;i<=n;i++){
			if(a[i][c]){k=i; break;}
		}
		if(a[k][c]){
			for(int j=1;j<=n+1;j++) swap(a[k][j],a[u][j]);
			for(int i=u+1;i<=n;i++){
				if(a[i][c]){
					for(int j=1;j<=n+1;j++){
						a[i][j]^=a[u][j];
					}
				}
			}
			u++;
		}
	}
	for(int i=u;i<=n;i++){ 
		if(a[i][n+1]) return -1;
	}
	return 1<<(n-u+1);
}
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
			scanf("%d",&s[i]);
		for(int j=1;j<=n;j++){
			scanf("%d",&e[j]);
			if(s[j]!=e[j])
				a[j][n+1]=1;
			a[j][j]=1;
		}			
		int x,y;
		while(scanf("%d%d",&x,&y)&&x+y){
			a[y][x]=1;
		}
		int ans=gauss();
		if(ans==-1)
			printf("Oh,it's impossible~!!\n");
		else
			printf("%d\n",ans);
	}
	return 0;
}
