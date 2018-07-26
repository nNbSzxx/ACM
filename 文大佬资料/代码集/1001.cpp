#include<bits/stdc++.h> 

using namespace std;

const int M  =  14;
int A[M],B[M];
int ans1[1000],ans2[1000];
char C[M];
int n;
int main(){
	while(cin>>C){
	cin>>n;
	memset(A,0,sizeof(A));
	memset(ans2,0,sizeof(ans2));
	memset(ans1,0,sizeof(ans1));
	int ct=strlen(C),ct1;
	ct1=ct;
	for(int i=0;i<strlen(C);i++){
		if(C[i]=='.') ct=i;
	}
	for(int i=0;i<ct;i++){
		A[i+7-ct]=C[i]-'0';
	}
	for(int i=1;i+ct<strlen(C);i++){
		A[6+i]=C[i+ct]-'0';
	}
	ans1[500]=1;
	int left=500,right=500;
	for(int k=1;k<=n;k++){
		for(int i=left;i<=right;i++){
			for(int j=1;j<=6;j++){
				ans2[i-6+j]+=ans1[i]*A[j]; 
				///printf("%d %d %d %d\n",i,j,i-6+j,ans1[i]*A[j]);
				}
		} 
		for(int i=left;i<=right;i++){
			for(int j=7;j<=12;j++){
				ans2[i+j-6]+=ans1[i]*A[j]; 
			}
		} 
		
		for(int i=999;i>=1;i--){
			ans2[i-1]+=ans2[i]/10;
			ans2[i]%=10; 
		}
		left=0,right=0; 
		for(int i=999;i>=1;i--) {
			if(ans2[i]) {
				right=i;
				break;
			}
		}
		
		for(int i=1;i<=999;i++) {
			if(ans2[i]) {
				left=i;
				break;
			}
			
		}
		
		
		for(int i=1;i<=999;i++){
			ans1[i]=ans2[i];ans2[i]=0;
		}
		
	}
	if(left==0&&right==0){
		puts("0\n");
	}
	else if(left<=500&&right>500){
		for(int i=left;i<=500;i++){
			printf("%d",ans1[i]);
		}
		printf(".");	
		for(int i=501;i<=right;i++){
			printf("%d",ans1[i]);
		}
	}
	else if(left<=500&&right<=500){
		for(int i=left;i<=right;i++){
			printf("%d",ans1[i]);
		}
		for(int i=right+1;i<=500;i++) printf("0");
	}
	else if(left>500&&right>500){
		printf(".");
		for(int i=501;i<left;i++){
			printf("0");
		}
		for(int i=left;i<=right;i++){
			printf("%d",ans1[i]);
		}
	
	}
	puts("");
	}
	return 0;
}
