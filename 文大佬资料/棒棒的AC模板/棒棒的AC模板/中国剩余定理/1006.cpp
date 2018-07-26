#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
const int Mod=23*28*33;

long long extend_gcd(long long a,long long b,long long &x,long long &y){
	if(b==0){
		x=1,y=1;
		return a; 
	}
	extend_gcd(b,a%b,x,y);
	long long tmp=x;x=y;y=tmp-a/b*y;
	return a;
}

long long gcd(long long a,long long b){
	return b==0?a:gcd(b,a%b);
}

long long A,B,C,D,ans;

int get_phi(int num){
	int p=0;
	for(int i=1;i<=num;i++){
		if(gcd(i,num)==1) p++;
	} 
	return p-1;
}
long long quick_pow(long long num,long long mod,int ct){
	long long ans=1;
	
	while(ct){
		if(ct%2==1) {
			ans=ans*num;
			ans=ans%mod;
		}
		num=num*num;
		num=num%mod;
		ct=ct/2;
	}
	return ans;
}
long long sum;
int main(){
	int phi23=get_phi(23);
	int phi28=get_phi(28);
	int phi33=get_phi(33);
//	printf("%d %d %d\n",phi23,phi28,phi33);

	int time=1;
	while(1){
		sum=0;
		cin>>A>>B>>C>>D;
		if(A+B+C==0){
		 cout<<"Case "<<time++<<": the next triple peak occurs in "<<Mod-D<<" days."<<endl;
		 continue;
		}
		if(A==-1) break;
		long long ans1=23*28;
		sum=sum+ans1*quick_pow(ans1,33,phi33)*C;
		sum=sum%Mod;
		
		long long ans2=23*33;
		sum=sum+ans2*quick_pow(ans2,28,phi28)*B;	
		sum=sum%Mod;
		
		long long ans3=33*28;
		sum=sum+ans3*quick_pow(ans3,23,phi23)*A;	
		sum=sum%Mod;
		if(((sum-D)%Mod+Mod)%Mod==0)cout<<"Case "<<time++<<": the next triple peak occurs in "<<Mod<<" days."<<endl;
		else cout<<"Case "<<time++<<": the next triple peak occurs in "<<((sum-D)%Mod+Mod)%Mod<<" days."<<endl;
	}
	return 0;
}
