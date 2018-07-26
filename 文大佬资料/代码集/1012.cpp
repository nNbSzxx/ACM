#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;

int check(int K,int m){
	int ans=1,ct=2*K,s=0;
	for(int i=1;i<=K;i++){
		s=(s+m-1)%ct;
		if(s<K) return 0;
		ct--;
	}
	return 1; 
}
int num[20];
int main(){
	int n;
	while(cin>>n){
		if(n==0) break;
		if(num[n]){
			printf("%d\n",num[n]);
			continue;
		}
		for(int i=n+1;;i=i+n+1){
			if(check(n,i)){
				num[n]=i;
				printf("%d\n",i);break;
			}
			if(check(n,i+1)){
				num[n]=i+1;
				printf("%d\n",i+1);break;
			}
		}
	}
	return 0;
}
