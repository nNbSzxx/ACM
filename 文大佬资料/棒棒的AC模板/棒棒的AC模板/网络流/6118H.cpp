#include<cstdio>
#include<algorithm>
#include<iostream>
#include<cstring>
using namespace std;

const int N=6100,INF=0x3f3f3f3f;
const int BIG=12345678;
const int M=N*10;
int pre[N],d[N],p[N],ans;
int cnt,head[N];
int q[M],l,r;
struct edge{
    int u,v,w,c,next;
}e[M];
void init(){
    memset(head,-1,sizeof(head));
    ans=cnt=0;
}
void addedge(int u,int v,int c,int w){
    e[cnt].u=u,e[cnt].v=v,e[cnt].w=w,e[cnt].c=c;
    e[cnt].next=head[u],head[u]=cnt++;
    e[cnt].u=v,e[cnt].v=u,e[cnt].w=-w,e[cnt].c=0;
    e[cnt].next=head[v],head[v]=cnt++;
}
int updata(int s,int t){
    int i,f=INF,sum=0;
    for(i=t;i!=s;i=e[pre[i]].u)
        f=min(f,e[pre[i]].c);
    for(i=t;i!=s;i=e[pre[i]].u){
       e[pre[i]].c-=f;
       e[pre[i]^1].c+=f;
       sum+=f*e[pre[i]].w;
    }
    if(sum/f>=2000) return 1;
       //printf("CCC%d %d\n",sum,f);
    ans=ans-sum+f*2000;
    return 0;
}
int spfa(int s,int t){
    int i,u,v,w;
    memset(p,0,sizeof(p));
    memset(pre,-1,sizeof(pre));
    memset(d,0x3f,sizeof(d));
    l=r=0;
    q[++r]=s,p[s]=1,d[s]=0;
    while(l<r){
        p[u=q[++l]]=0;
        for(i=head[u];i!=-1;i=e[i].next){
            v=e[i].v,w=e[i].w;
            if(e[i].c&&d[v]>d[u]+w){
                d[v]=d[u]+w;
                pre[v]=i;
                if(!p[v]){
                    p[v]=1;
                    q[++r]=v;
                }
            }
        }
    }
    if(pre[t]==-1)return 0;
    return 1;
}
int MiCMaF(int s,int t){
    ans=0;
    while(spfa(s,t))
        if(updata(s,t))
            return 0;
        
}
int A,B,C,D;
int main(){
    int n,m;
    while(cin>>n>>m){
        init();
        for(int i=1;i<=n;i++){
            scanf("%d%d%d%d",&A,&B,&C,&D);
            addedge(0,i,B,A);
            addedge(i,n+1,D,2000-C);
        }
        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&A,&B,&C);
            addedge(A,B,BIG,C); 
            addedge(B,A,BIG,C);
        }
        MiCMaF(0,n+1);
        printf("%d\n",ans);
    } 
    return 0;
}
