#include<iostream>
#define P 1000000007
#define ll long long
using namespace std;
ll n,m;
ll qpow(ll a,ll b){
	ll ans=1;
	for(ll i=b;i;i>>=1,a=(a*a)%P)
		if(i&1)ans=ans*a%P;
	return ans;
}
ll C(ll a,ll b){
	if(b>a)return 0;
	if(b>a-b)b=a-b;
	ll s1=1,s2=1;
	for(ll i=1;i<=b;i++)
	{
		s1=s1*(a-i+1)%P;
		s2=s2*i%P;
	}
	return s1*qpow(s2,P-2)%P;
}
ll lucas(ll a,ll b){
	return C(a/P,b/P)*C(a%P,b%P);
}
int main()
{
	n=read();m=read();
	printf("%lld",(lucas(n,m)+max(n,m))%P);
	return 0;
}
