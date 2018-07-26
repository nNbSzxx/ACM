#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>

using namespace std;
const int M = 300; 
int a[M];
int n;
int ans[4];
int ans2[500000],ans3[500000];
int cmp(int A,int B){
	return A>B?1:0;
}
int lim;
//A 种数， B 张数，C最大 
int get_ans(int A,int B,int C){
	if(A==ans[1]&&B==ans[2]&&C==ans[3]) {
		ans[0]++;return 0;
	}
	else if(A>ans[1]||A==ans[1]&&B<ans[2]||A==ans[1]&&B==ans[2]&&C>ans[3]){
		ans[0]=0;ans[1]=A;ans[2]=B;ans[3]=C;
		for(int i=1;i<=B;i++) ans3[i]=ans2[i];
		ans3[0]=B;
		return 0;
	}
	return 0;
}
int dfs(int val,int ct,int A,int B,int C){
	/*printf("ABC%d\n",val);
	for(int i=1;i<=B;i++){
		printf("%d ",ans2[i]);
	}
	printf("\n");
*/
	if(val==0){
		get_ans(A,B,C);
		return 0;
	
	}
	//printf("AAAAAAAAAAAAAAAA%d %d ",ans[1],lim);
	if(ans[1]==lim&&B>ans[2]) return 0;	
	if(B==4) return 0;
	for(int i=ct;i<=n;i++){
		if(a[i]>val) break;
		if(a[i]==-1) continue;
		ans2[B+1]=a[i];
		if(ct!=i){ 
			dfs(val-a[i],i,A+1,B+1,max(C,a[i]));
		} 
		else {
			dfs(val-a[i],ct,A,B+1,C);
		}
	}
	return 0;
}
int get_lim(int m){
	lim=min(lim,n);
	int sum=0;
	for(int i=1;i<=4;i++) {
		sum=sum+a[i];
		if(sum>m) lim=min(lim,i-1); 
	}
	return 0;
}
int main(){
	int tmp;
	while(cin>>tmp){
		memset(a,0,sizeof(a));
		
		n=1;
		a[n]=tmp;
	while(1){
		n++;
		cin>>tmp;
		if(tmp==0) break;
		a[n]=tmp; 
	}
	n--;
	sort(1+a,1+a+n);
	//for(int i=1;i<=n;i++) printf("%d ",a[i]);puts("");
	a[0]=-1;
	while(1){
		lim=4;
		memset(ans,0,sizeof(ans));
		memset(ans2,0,sizeof(ans2));
		
		
		cin>>tmp;
	
		if(tmp==0) break;
	//	printf("SD%d %d %d\n",tmp,lim,a[1]);
	//	get_lim(tmp);printf("LIM%d %d\n",lim,n);
		dfs(tmp,0,0,0,0);
		printf("%d ",tmp);
		if(ans[0]){
			printf("(%d): tie\n",ans[1]);
		}
		else if(ans[1]==0){
			puts("---- none");
		}
		else {
			printf("(%d): ",ans[1]);
			for(int i=1;i<=ans3[0];i++){
				printf("%d ",ans3[i]);
			}
			printf("\n");
		}
	}
	}
}
