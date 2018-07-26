#include<bits/stdc++.h> 

using namespace std;
const int M = 5000+123;
long long a[M];
long long  f[2][M*2];
struct pos{
	int x,y;
}P[M*M];
int sz;
int bin[20];
int main(){
	freopen("A.in","r",stdin); 
	bin[0]=0;
	bin[1]=1;
	for(int i=2;i<18;i++) bin[i]=bin[i-1]*2;
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		for(int i=1;i<n;i++){
			cin>>a[i];
		}
		for(int j=0;j<=n;j++){
			f[0][j]=-123456789;
			f[1][j]=-123456789;
		} 
		sz=0;
		f[0][0]=n*a[1]; 
		int flag=0;
		for(int i=1;i<=n-2;i++){
			int K=(n-2)/i;//拆分一个大小为K的背包 
			int j=0;
			for(int j=1;;j++){
				if(bin[j]>K)break;
				sz++;
				P[sz].x=bin[j];
				P[sz].y=i;
				K-=bin[j];
			}
			if(K){
				sz++;
				P[sz].x=K;
				P[sz].y=i;
			}
		}
		for(int i=1;i<=sz;i++){
			flag=flag^1;
			for(int j=0;j<=n-2;j++){
				f[flag][j]=f[flag^1][j];
				if(j-P[i].x*P[i].y<0) continue;
				//printf("HH%d %d %d %d %d %d\n",f[flag][j],i,j,P[i].x,P[i].y,j);
				f[flag][j]=max(f[flag][j],f[flag^1][j-P[i].x*P[i].y]+P[i].x*(a[P[i].y+1]-a[1]));
			}
		}
		printf("%lld\n",f[flag][n-2]);
	}
	return 0;
} 
