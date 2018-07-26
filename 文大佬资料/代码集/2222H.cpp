#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int M = 523456;
int ch[M][27];
int f[M],last[M];
short val[M];
bool vis[M];
char ts[55];
int q[M];
char ss[M*4];
int L;
int idx(char c){return c-'a';}
int sz;
int n;
int init(){
	sz=0;
	memset(ch[0],0,sizeof(ch[0]));
	for(int i=0;i<=L;i++){
		val[i]=0;
		vis[i]=0;
		last[i]=0;
		f[i]=0;
		for(int j=0;j<26;j++)
                ch[i][j]=0;
	}
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
	for(int c=0;c<26;c++){
		int u=ch[0][c];
		if(u){
			f[u]=0,q[++right]=u,last[u]=0;
		}
	}
	while(left<=right){
		int r=q[left];
		//printf("A%d\n",r);
		left++;
		if(left>M) left=0;
		for(int c=0;c<26;c++){
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
	
int ans;
int count(int u){
	if(u){
		if(!vis[u]){
			vis[u]=1;
			ans+=val[u];
			count(last[u]);
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
	
	

int main(){
	freopen("A.in","r",stdin);
	int T;
	cin>>T;
	while(T--){
		L=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++) {
			scanf("%s",ts);
			L+=strlen(ts);
			insert(ts);
		} 
		get_fail();
		ans=0;
		scanf("%s",ss);
		find(ss);
		cout<<ans<<endl;
		
		init();
	} 
	return 0;
} 
