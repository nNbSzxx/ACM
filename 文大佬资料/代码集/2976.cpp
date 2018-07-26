#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<iostream>
#include<cmath>
using namespace std;
const int  M=  1000+123; 
double d[M];
double a[M],b[M];
const double eps= 1e-6;
int n,K;
double ans;
bool cmp(double A,double B){
	return A>B;
}

double check(double f){
	for(int i=1;i<=n;i++){
		d[i]=a[i]-b[i]*f;
	}
	sort(d+1,d+1+n,cmp);
	double sum=0.0;
	for(int i=1;i<=n-K;i++){
		sum=sum+d[i];
	}
	return sum;	
}
double binary(double l,double r){
	while(r-l>1e-6){
		double mid=(l+r)/2.0;
		if(check(mid)<0.0)r=mid;
		else l=mid;
	} 
	return r;
}

int main(){
	
	while(1){
		scanf("%d%d",&n,&K);
		ans=0.0;
		if(n+K==0) break;
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<=n;i++)cin>>b[i];
		printf("%d\n",(int)(binary(0.0,1.0)*100.0+0.5));	
	}
	return 0; 

} 
