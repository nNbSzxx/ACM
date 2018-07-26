#include<bits/stdc++.h> 
using namespace std;
long long extend_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	long long ans=extend_gcd(b,a%b,x,y);
	long long tmp=x;
	x=y;
	y=tmp-a/b*y;
	return ans;
}
long long cal(long long a,long long b,long long c){
	long long x,y;
	long long gcd=extend_gcd(a,b,x,y);
	if(c%gcd!=0) return -1;
	x*=c;
	x/=gcd;
	b/=gcd;
	if(b<0) b=-b;
	long long ans=x%b;
	if(ans<=0) ans+=b;
	return ans;
}
int main(){
	//freopen("data.in","r",stdin);
    long long x,y,m,n,L;  
    while(scanf("%lld%lld%lld%lld%lld",&x,&y,&m,&n,&L)!=EOF)  {  
        long long ans=cal(m-n,L,y-x);  
        if(ans==-1) printf("Impossible\n");  
        else printf("%lld\n",ans);  
    }  
    return 0;  
}  
