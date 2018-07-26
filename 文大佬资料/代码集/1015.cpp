#include<bits/stdc++.h> 
using namespace std;
const int M  = 1234;
const int magic=400;
int f[30][M];
int ct[30][M];
int pre1[30][M],pre2[30][M];
int a[M],b[M],c[M];

int main(){
	while(1){
		int n,m;
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		for(int i=1;i<=n;i++){
			c[i]=a[i]-b[i];
		}
		for(int i=1;i<=n;i++){
			for(int j=m-1;j>1;j++){
				for(int k=0;k<=800;k++){
					int tmp=c[i]+k;
					if(!f[j][k]) continue;
					if(f[j+1][k+tmp]<f[j][k]+a[i]+b[i]){
						f[j+1][k+tmp]=f[j][k]+a[i]+b[i];
						ct[j+1][k+tmp]=i;
						pre1[j+1][k+tmp]=j;
						pre1[j+1][k+tmp]=k;
					}
				}
			} 
		}
	}
	return 0;
}
