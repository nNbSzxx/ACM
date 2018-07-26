#include<cstdio> 
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector> 
using namespace std;
const int M = 223456;
int ch[M][27];
int f[M],last[M];
short val[M];
bool vis[M];
int q[M];
int idx(char c){return c-'a';}
int sz,L;
int ct[M];
vector<int> G[M]; 
vector<int> R[M];//哪些儿子是存在的 
vector<int> CC[M];//反向建立fail树 

struct pos{
	int x,y;
	pos(int x=0,int y=0):x(x),y(y){}
}P[M];

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

int insert(int num,char *s){
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
	ct[num]=u;
	return 0;
}

int get_fail(){
	int left=1,right=0;
	f[0]=0;
	for(int c=0;c<26;c++){
		int u=ch[0][c];
		if(u){
			f[u]=0,q[++right]=u,last[u]=0;
			CC[0].push_back(u); 
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
			else CC[r].push_back(u);
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
	
int Ans;
int count(int u){
	if(u){
		if(!vis[u]){
			vis[u]=1;
			Ans+=val[u];
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

char ss[M],ts[M];
int c[M];
int lowbit(int x){
	return x&(-x);
}
int add(int x,int val){
	for(int i=x;i<M;i+=lowbit(i))
		c[i]+=val;
	return 0;
}
int query(int x){
	int sum=0;
	for(int i=x;i>0;i-=lowbit(i))
		sum+=c[i];
	return sum;
}

int l[M],r[M];
int times; 
int dfs(int num){
	l[num]=++times;
	for(int i=0;i<G[num].size();i++){
		dfs(G[num][i]);
	}
	r[num]=++times;
	return 0;
}

int ans[M];
int solve(int num){
	add(l[num],1);
	if(val[num]){ 
		for(int i=0;i<R[num].size();i++){
			int to=ct[P[R[num][i]].x];
			ans[P[R[num][i]].y]=query(r[to])-query(l[to]-1);
		}
	} 
	for(int i=0;i<CC[num].size();i++){
		solve(CC[num][i]);
	}
	add(l[num],-1);
	return 0;
}

int read(){
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x;
}

int main(){
	freopen("A.in","r",stdin);
	scanf("%s",ss);
	L=strlen(ss);
	int tmp=0;
	int n=0,m;
	for(int i=0;i<L;i++){
		if(ss[i]=='P'){
			ts[tmp]='\0';
			insert(++n,ts);
		}
		else if(ss[i]=='B'){
			tmp--;
		}
		else {
			
			ts[tmp++]=ss[i];
		}
	} 
	get_fail();
	cin>>m;
	for(int i=1;i<=sz;i++){
		G[f[i]].push_back(i);
	}
	dfs(0);		
	for(int i=1;i<=m;i++){
		P[i].x=read();
		P[i].y=read();
		R[ct[P[i].y]].push_back(i);
		P[i].y=i;
	}
	solve(0);

	for(int i=1;i<=m;i++){
		printf("%d\n",ans[i]);
	} 
	return 0;
} 
