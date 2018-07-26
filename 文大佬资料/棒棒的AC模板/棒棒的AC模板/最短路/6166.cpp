#include<bits/stdc++.h>
#define mst(a,b) memset(a,b,sizeof(a))
#define F(i,a,b) for(int i=(a);i<=(b);++i)
using namespace std;
typedef long long ll;

const int N=2e5+7;ll inf=1ll<<60;
int g[N],v[N],nxt[N],w[N],ed;
int t,n,m,k,a[N],Q[N],in[N],cas;
ll d[N];
struct EDGE{int a,b,c;}edge[N];

void adg(int x,int y,int z){v[++ed]=y,w[ed]=z,nxt[ed]=g[x],g[x]=ed;}

ll spfa(int S,int T)
{
    F(i,1,T)d[i]=inf,in[i]=0;
    d[S]=0,Q[1]=S,in[S]=1;
    unsigned short l=1,r=2;
    while(l!=r)
    {
        int x=Q[l++];in[x]=0;
        for(int i=g[x];i;i=nxt[i])
            if(d[v[i]]>d[x]+w[i])
            {
                d[v[i]]=d[x]+w[i];
                if(!in[v[i]])in[v[i]]=1,Q[r++]=v[i];
            }
    }
    return d[T];
}

int main(){
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d",&n,&m);
        F(i,1,m)scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        scanf("%d",&k);
        F(i,1,k)scanf("%d",a+i);
        int S=n+1,T=n+2,pre=ed,now;
        ll ans=inf;
        F(i,0,17)
        {
            mst(g,0),ed=0,now=1<<i;
            F(j,1,m)adg(edge[j].a,edge[j].b,edge[j].c);
            F(j,1,k)
            {
                if(a[j]&now)adg(S,a[j],0);
                else adg(a[j],T,0);
            }
            ans=min(ans,spfa(S,T));
            mst(g,0),ed=0;
            F(j,1,m)adg(edge[j].a,edge[j].b,edge[j].c);
            F(j,1,k)
            {
                if((a[j]&now)==0)adg(S,a[j],0);
                else adg(a[j],T,0);
            }
            ans=min(ans,spfa(S,T));
        }
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
