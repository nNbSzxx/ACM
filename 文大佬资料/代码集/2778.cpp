#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int M = 523456;
int ch[M][27];
int f[M],last[M];
int val[M];
bool vis[M];
int q[M];
int idx(char c){return c-'A';}
int sz;

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

	
	

int main(){
	freopen("A.in","r",stdin);
	int n,m;
	cin>>n>>m;
	char t[23];
	for(int i=1;i<=n;i++){
		cin>>t;
		insert(t);
	}
	get_fail();
	
	return 0;
} 
