#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int M = 1e+9;
const int N = 37;
long long dt[40];
long long G[38][500000];
int dfs(int num,int lim,int K,long long ans){
	//printf("%d\n",ans);
	if(ans>M) return 0;
	if(num==lim/2+1){
		if(lim%2==1){
			for(int i=1;i<K;i++){
				ans=ans+dt[lim/2];
				if(ans>M) break;
				G[K][++G[K][0]]=ans;
			}
		}
		if(lim!=1){G[K][++G[K][0]]=ans;}
		return 0;
	}
	if(num!=1)dfs(num+1,lim,K,ans);
	for(int i=1;i<K;i++){
		dfs(num+1,lim,K,ans+i*(dt[lim-num]+dt[num-1]));
	}
}
int init(){

	for(int i=2;i<=N;i++){
		G[i][0]=1,G[i][1]=0;
	}
	for(int i=2;i<=N;i++){
		long long t=0;
		//memset(dt, 0, sizeof dt);
		dt[0]=1;
		for(int j=1;t<M;j++){
			dfs(1,j,i,0);
			t=t*i+(i-1);
			dt[j]=dt[j-1]*i;
			//printf("%d %d\n",i,j);
		}
	}
	for(int i=2;i<=N;i++){
		sort(1+G[i],1+G[i]+G[i][0]);
	}
	/*for(int i=10;i<=10;i++){
		for(int j=1;j<=G[i][0];j++){
			printf("%lld ",G[i][j]);
		}
		printf("\n");
	}*/
	return 0;
}

int dive(int K,int num){
	int left=1,right=G[K][0];
	int ans=1;
	while(left<=right){
		int mid=(left+right)>>1;
		if(G[K][mid]<=num){
			ans=max(ans,mid);
			left=mid+1;
		}
		else right=mid-1;
	}
	return ans;
}
int main(){
	//freopen("B.txt","r",stdin);
	init();
	int T;
	cin>>T;
	for(int tt=1;tt<=T;tt++){
		printf("Case #%d: ",tt);
		int L,R,l,r;
		cin>>L>>R>>l>>r;
		long long sum=(long long)(r-l+1)*(R-L+1);

		for(int i=l;i<=r;i++){
			sum=sum+(dive(i,R)-dive(i,L-1))*(i-1);
			//printf("%lld\n",dive(i,R));
			//printf("%lld\n",dive(i,L-1));
		}
		printf("%lld\n",sum);
	}
}
