#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring> 
using namespace std;
const long long  M = 500;
long long  A,B;
long long  a[M],b[M],cnt;
long long  div(){
	long long  tmp=A;
	for(long long  i=2;i*i<=A;i++){
		if(tmp%i) continue;
		cnt++;
		a[cnt]=i;
		b[cnt]=0;
		while(tmp%i==0){
			b[cnt]++;
			tmp=tmp/i;
		}
	}
	if(tmp>1) a[++cnt]=tmp,b[cnt]=1;
	return 0;
}
long long multi(long long at,long long bt,long long mod){
    long long ans = 0;
    at%=mod;
    while(bt){
        if(bt & 1){
            ans = (ans + at) % mod;
            bt--;
        }
        bt >>= 1;
        at= (at + at) % mod;
    }
    return ans;
}
long long pow(long long  X,long long  Y,long long  mod){
	//printf("%lld %lld %lld\n",X,Y,mod);
	long long tmp=X%mod,ans=1;
	while(Y){
		if(Y&1){
			ans=multi(ans,tmp,mod);
			ans=ans%mod;
		}
		tmp=multi(tmp,tmp,mod);
		tmp=tmp%mod;
		Y=Y/2;
	}
	return ans%mod; 
}
long long  work(long long  i,long long  Y,long long  mod){
	return  (pow(a[i],Y,mod)+mod-1)%mod/(a[i]-1);
}
long long C;
int main(){
	freopen("A.in","r",stdin);
	while(scanf("%lld%lld",&A,&B)!=EOF){
		cnt=0;
		div();
		//for(int i=1;i<=cnt;i++) printf("%d %d\n",a[i],b[i]);
		long long ans=1;
		for(long long  i=1;i<=cnt;i++){
			
			ans=ans*work(i,B*b[i]+1,(a[i]-1)*9901);
			ans=ans%9901;
		}
		cout<<ans<<endl;
	}
}
