#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
using namespace std;
const int M = 100;
char s[M];
int c[M];
unsigned long long n;
long long m;
int len;
int vis[M];
int lim[M];
int lim2[M];
int check(){
	memset(vis,0,sizeof(vis));
	int i=1;
	while(n){
		if(n&1){
			if(i>len){
				printf("Impossible\n");
				return 0;
			}
			int tmp=i;
			while(1){
				if(tmp>len){
					printf("Impossible\n");
					return 0;
				}
				if(lim[tmp]>vis[tmp]){
					vis[tmp]++;break;
				}
				else vis[tmp]--;
				tmp++;	
			}
		}
		n=n/2;
		i++;
	}
	return 1;
}
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		scanf("%d",&len);
		scanf("%s",s+1);
		memset(c,0,sizeof(c));
		for(int i=1;i<=len;i++){
			if(s[i]=='p') c[i]=1,lim[i]=1;
			else c[i]=-1,lim[i]=0;  
		}
		cin>>m;
		n=m;
		if(m==0){
			for(int i=1;i<=len;i++){printf("0");}
			puts("");
			continue;
		}
		else if((m>>1)<=0&&m!=1){
			n=-m;
			for(int i=1;i<=len;i++) c[i]=c[i]*(-1),lim[i]=lim[i]^1;
		}
		
		for(int i=1;i<=len/2;i++){
			swap(c[i],c[len+1-i]);
			swap(lim[i],lim[len+1-i]);
		}
		for(int i=1;i<=len;i++) {
			lim2[i]=lim[i]-1;
		}	
		if(check()){
			for(int i=len;i>=1;i--)
				printf("%d",abs(vis[i]));
			printf("\n");
		}
		
	}
	return 0;
}
