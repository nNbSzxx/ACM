#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

#define inf 1<<30
#define eps 1e-3
const int M = 1234;
struct Edge{
    int v,w,next;
}edge[M*10];
int head[M];
double dist[M];
bool mark[M];
int value[M],cost[M];
int _count[M];
int n,m,NE;
int insert(int u,int v,int w){
    edge[NE].v=v;
    edge[NE].w=w;
    edge[NE].next=head[u];
    head[u]=NE++;
	return 0;
}

bool SPFA(double mid){
    memset(mark,false,sizeof(mark));
    memset(_count,0,sizeof(_count));
    for(int i=1;i<=n;i++)dist[i]=inf;
    dist[1]=0;
    queue<int>Q;
    Q.push(1);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();
        mark[u]=false;
        _count[u]++;
        if(_count[u]>n)return true;
        for(int i=head[u];i!=-1;i=edge[i].next){
            int v=edge[i].v,w=edge[i].w;
            double tmp=mid*w-value[v];
            if(dist[u]+tmp<dist[v]){
                dist[v]=dist[u]+tmp;
                if(!mark[v]){ mark[v]=true;Q.push(v); }
            }
        }
    }
    return false;
}

int solve(){
    double left=0,right=10000,mid;
    while(right-left>eps){
        mid=(left+right)/2;
        if(SPFA(mid))left=mid;
        else right=mid;
    }
    printf("%.2f\n",left);
	return 0;
}
               

int main(){
    int u,v,w;
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++)scanf("%d",&value[i]);
        NE=0;
        memset(head,-1,sizeof(head));
        while(m--){
            scanf("%d%d%d",&u,&v,&w);
            insert(u,v,w);
        }
        solve();
    }
    return 0;
}
