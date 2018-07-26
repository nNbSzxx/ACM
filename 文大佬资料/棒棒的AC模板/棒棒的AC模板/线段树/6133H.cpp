#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
const int  M= 1e+5+123;

int cnt;
struct pos{
    int l,r,sz;
    long long sum,val;
    pos(int l=0,int r=0,int sz=0,long long sum=0,long long val=0) : l(l),r(r),sz(sz),sum(sum),val(val){}
}tree[M*18];
void build(int &node,int l,int r,int pos,int val){
    node = ++cnt;
    tree[node].sum = tree[node].val = val;
    tree[node].sz = 1; 
    tree[node].l = tree[node].r = 0;
    if(l == r) return;
    int mid = (l+r)>>1;
    if(pos <= mid) build(tree[node].l,l,mid,pos,val);
    else build(tree[node].r,mid+1,r,pos,val);
}

int merg(int A,int B,int l,int r){
    if(A==0||B==0) return A+B;
    if(l==r){
        tree[A].val=tree[A].val+tree[B].val;
        tree[A].val=tree[A].val+tree[B].sz*tree[A].sum;
        tree[A].sz+=tree[B].sz;
        tree[A].sum+=tree[B].sum;
        return A;
    }
    int mid=(l+r)>>1;
    tree[A].l=merg(tree[A].l,tree[B].l,l,mid);
    tree[A].r=merg(tree[A].r,tree[B].r,mid+1,r);
    tree[A].sum =tree[tree[A].l].sum +  tree[tree[A].r].sum;  
    tree[A].sz = tree[tree[A].l].sz +  tree[tree[A].r].sz;  
    tree[A].val =tree[tree[A].l].val +  tree[tree[A].r].val;
    tree[A].val += tree[tree[A].l].sum * tree[tree[A].r].sz;      
    return A;
}

int n;
int rot[M],vis[M];
vector<int> G[M];
long long Ans[M];
int stk[M];
int fa[M];
int dfs2(int u){
    int sz=1;
    stk[1]=u;
    fa[u]=0;
    while(sz){
        int u=stk[sz];

        vis[u]++;
        if(vis[u]==1){
            for(int i=0;i<G[u].size();i++){
                int v=G[u][i];
                 if(v != fa[u]){
                     fa[v]=u;
                     stk[++sz]=v;
                }
            }
        }
        if(vis[u]==2){
            Ans[u] = tree[rot[u]].val;
            if(fa[u])merg(rot[fa[u]],rot[u],1,n);
            sz--;
        }
        //printf("%d %d %d\n",u,sz,vis[u]);
    }
    
    return 0;
}
int c[M],b[M];
int init(){
    for(int i=1;i<=cnt;i++)
        tree[i].val=0,tree[i].sum=0;
    cnt=0;
    for(int i=1;i<=n;i++){
        G[i].clear();
        Ans[i]=0; 
        fa[i]=0;
        rot[i]=0;
        vis[i]=0;
        c[i]=0;
    } 
    return 0;
}
struct value{
    int x,y;
    value(int x=0,int y=0):x(x),y(y){}
}a[M];
int cmp(value A,value B){
    return A.x<B.x;
}

int main(){
//    freopen("1001.in","r",stdin);
//    freopen("1001.ans2","w",stdout); 
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
    
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i].x);
            a[i].y=i;
        
        }
        sort(1+a,1+a+n,cmp);
        int ct=0,last=-1;
        for(int i=1;i<=n;i++){
            if(last!=a[i].x){
                ct++;
                last=a[i].x;
            }
            c[a[i].y]=ct;
            b[ct]=a[i].x;
        }
        
        for(int i=1;i<=n;i++){
                build(rot[i],1,n,c[i],b[c[i]]);
        }
        for(int i=1;i<n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            G[x].push_back(y);
            G[y].push_back(x);
        }
   	
        dfs2(1);
        for(int i=1;i<=n;i++){
            printf("%lld",Ans[i]);
            if(i!=n) printf(" ");
            else printf("\n");
        }
    	init();
    } 
    return 0;
} 
