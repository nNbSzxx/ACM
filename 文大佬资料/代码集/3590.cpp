#include<bits/stdc++.h> 

using namespace std;
const long long M = 123;
long long f[M][M];
long long gcd(long long A,long long B){
	return B==0?A:gcd(B,A%B);
}
long long n,ans;
long long p[26] ={1,2, 3, 5, 7, 11, 13, 17, 19, 23, 
			29, 31, 37, 41, 43, 47, 53, 59,
			61, 67, 71, 73, 79, 83, 89, 97};  
long long DP(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=0;
		}
	}
	for(int i=0;i<=n;i++) f[i][0]=1;
	for(int i=1;i<=25;i++){
		for(int j=1;j<=n;j++){
			f[i][j]=max(f[i][j],f[i-1][j]);
			f[i][j]=max(f[i][j],f[i][j-1]);
		}
		for(int k=0;k*p[i]<=n;k++){
				for(int j=k*p[i];j<=n;j++){
				long long tmp=f[i-1][j-k*p[i]];
				if(!tmp) continue;
				f[i][j]=max(f[i][j],tmp/gcd(tmp,k*p[i])*k*p[i]);
			}
		}
	}
	return 0;
}
 

long long c[M];

long long divd(long long num){
	c[0]=0;
	for(long long i=1;i<=25;i++){
		if(num%p[i]==0) c[++c[0]]=1;
		while(num%p[i]==0){
			c[c[0]]*=p[i];
			num=num/p[i];
		}
	}
	return 0;
}

int main(){
	long long T;
	cin>>T;
	while(T--){
		cin>>n;
		DP();
		long long k=n-1;
		ans=f[25][n];
		while(f[25][k]==ans) k--;
		k++;
		printf("%lld",f[25][n]);
		for(long long i=1;i<=n-k;i++) printf(" %lld",i);
		divd(f[25][n]);
		long long num=n-k;
		sort(c+1,c+1+c[0]);
		for(long long i=1;i<=c[0];i++){
			long long ct=++num;
			for(long long j=1;j<c[i];j++){
				++num;
				printf(" %lld",num);
			}
			printf(" %lld",ct);
		}
		printf("\n");
	}
	return 0;
} 
