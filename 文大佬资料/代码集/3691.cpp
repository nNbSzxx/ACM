#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int M = 12345;
int ch[M][5];
int f[M],last[M],val[M];
bool vis[M];//与AC自动机每个点对应，用于统计 
char ts[55],ss[M];//ts是模式串，ss是匹配串 
int q[M];//手写队列  
int L,L2;//L2是匹配串长度 
int idx(char c){
	if(c=='A') return 1;
	if(c=='G') return 2;
	if(c=='C') return 3;
	if(c=='T') return 4;
}

int sz;//自动机长度
int init(){

	memset(ch[0],0,sizeof(ch[0]));
	for(int i=0;i<=sz;i++){
		val[i]=0;
		vis[i]=0;
		last[i]=0;
		f[i]=0;
		for(int j=0;j<5;j++)
                ch[i][j]=0;
	}
	sz=0;
	return 0; 
}

int insert(char *s){
	int len=strlen(s);
	int u=0;
	for(int i=0;i<len;i++){
		int c=idx(s[i]);
		if(!ch[u][c]){
			++sz;
			ch[u][c]=sz;
		}
		u=ch[u][c];
	}
	val[u]++;
	return 0;
}

int get_fail(){
	int left=1,right=0;
	f[0]=0;
	for(int c=1;c<5;c++){
		int u=ch[0][c];
		if(u)f[u]=0,q[++right]=u,last[u]=0;
	}
	while(left<=right){
		int r=q[left];
		left++;
		if(left>M) left=0;
		for(int c=1;c<5;c++){
			int u=ch[r][c];
			if(!u){
				ch[r][c]=ch[f[r]][c];
				continue;
			}
			right++;
			if(right>M) right=0;
			
			q[right]=u;
			int v=f[r];
			//while(v&&!ch[v][c]) v=f[v];
			f[u]=ch[v][c];
			last[u]=val[f[u]]?f[u]:last[f[u]];
		}
	}
	return 0;
}

int count(int u){
	if(u){
		if(val[u]) return val[u]; 
		if(!vis[u]){
			val[u]=count(last[u]);
			vis[u]=1;
		}
	}
	return 0;
}
	
int find(char *s){
	int len=strlen(s);
	int u=0;
	for(int i=0;i<len;i++){
		int c=idx(s[i]);
		u=ch[u][c];
		if(val[u]) count(u);
		else if(last[u]) count(last[u]);
	}
	return 0;
}
int ans;
int dp[M][M];
int DP(){	
	for(int i=0;i<=L2;i++){
		for(int j=0;j<=sz;j++){
			dp[i][j]=M*M;
		}
	}
	dp[0][0]=0;
	for(int i=0;i<L2;i++){
		for(int j=0;j<sz;j++){
			if(count(j)) continue;
			for(int k=1;k<=4;k++){
				int to=ch[j][k];
				if(idx(ss[i])!=k){
					dp[i+1][to]=min(dp[i+1][to],dp[i][j]+1);
				}
				else {
					dp[i+1][to]=min(dp[i+1][to],dp[i][j]);
				}
			}
		}
	}
	
	ans=M*M;
	for(int j=0;j<sz;j++){
		if(dp[L2][j]<ans&&!count(j)) ans=dp[L2][j];
	}
	
	return 0;
}
int n;
int main(){
	freopen("A.in","r",stdin);
	int t=0;
	while(1){
		L=0;//L是插入AC自动机所有串的长度 
		scanf("%d",&n);
		if(n==0) return 0;
		for(int i=1;i<=n;i++) {
			scanf("%s",ts);
			L+=strlen(ts);
			insert(ts);
		} 
		get_fail();
		cin>>ss;
		L2=strlen(ss);
		DP();
		t++;
		int tmp=0;
		printf("Case %d: ",t);
		if(ans==M*M){
			printf("-1\n");
		}
		else printf("%d\n",ans);
		init();
	} 
	return 0;
} 
