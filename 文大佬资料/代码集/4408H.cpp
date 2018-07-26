#include<bits/stdc++.h> 
#define N 405
#define M 4005

using namespace std;

typedef struct nod
{
    int a,b,c;
} node;
node edge[M];

bool op(node a,node b)
{
    return a.c<b.c;
}

int n,m,o,fa[N],ka[N];
long long ans,mod,gk[N][N],kir[N][N];

bitset<N> flag;
vector<int> gra[N];

int getfather(int x,int father[])
{
    if (father[x]!=x) father[x]=getfather(father[x],father);
    return father[x];
}

long long det(long long a[][N],int n) //Matrix-Tree定理求Kirchhoff矩阵
{
    for (int i=0;i<n;i++)
    for (int j=0;j<n;j++) a[i][j]%=mod;
    long long ret=1;
    for (int i=1;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        while (a[j][i])
        {
            long long t=a[i][i]/a[j][i];
            for (int k=i;k<n;k++) a[i][k]=(a[i][k]-a[j][k]*t)%mod;
            for (int k=i;k<n;k++) swap(a[i][k],a[j][k]);
            ret=-ret;
        }
        if (a[i][i]==0) return 0;
        ret=ret*a[i][i]%mod;
        //ret%=mod;
    }
    return (ret+mod)%mod;
}

void matrix_tree()
{
    for (int i=1;i<=n;i++) //根据访问标记找出连通分量
    if (flag[i])
    {
        gra[getfather(i,ka)].push_back(i);
        flag[i]=0;
    }
    for (int i=1;i<=n;i++) 
    if (gra[i].size()>1) //枚举连通分量
    {
        memset(kir,0,sizeof(kir));
        
        int len=gra[i].size();
        for (int a=0;a<len;a++)
        for (int b=a+1;b<len;b++)
        {
            int la=gra[i][a],lb=gra[i][b];
            kir[b][a]-=gk[la][lb];
            kir[a][b]=kir[b][a];
            kir[a][a]+=gk[la][lb];
            kir[b][b]+=gk[la][lb];
        } //构造矩阵

        long long ret=det(kir,len);
        ret%=mod;
        ans=(ans*ret%mod)%mod;

        for (int a=0;a<len;a++) fa[gra[i][a]]=i;
    }
    for (int i=1;i<=n;i++) //连通图缩点+初始化
    {
        fa[i]=getfather(i,fa);
        ka[i]=fa[i];
        gra[i].clear();
    }
}

int main()
{
    freopen("4408.txt","r",stdin);
    
    while (scanf("%d%d%lld",&n,&m,&mod)==3)
    {

        if (n==0&&m==0&&mod==0) break;
        for (int i=1;i<=m;i++) scanf("%d%d%d",&edge[i].a,&edge[i].b,&edge[i].c);
        sort(&edge[1],&edge[m+1],op);
        
        for (int i=1;i<=n;i++) gra[i].clear();
        for (int i=1;i<=n;i++) 
        {
            fa[i]=i;
            ka[i]=i;
        }
        flag.reset();
        memset(gk,0,sizeof(gk));
        ans=1;
        o=edge[1].c;
        for (int i=1;i<=m;i++)
        {
            int pa=getfather(edge[i].a,fa),pb=getfather(edge[i].b,fa);
            if (pa!=pb)
            {
                flag[pa]=1;
                flag[pb]=1; //访问标记
                ka[getfather(pa,ka)]=getfather(pb,ka);
                gk[pa][pb]++;
                gk[pb][pa]++; //邻接矩阵
            }
            if (i==m||edge[i+1].c!=o) //所有相同的边并成一组
            {
                matrix_tree();
                o=edge[i+1].c;
            }
        }

        bool done=true;
        for (int i=2;i<=n;i++)
        if(ka[i]!=ka[i-1]) 
        {
            done=false;
            break;
        }
        if (!done) printf("0\n");
        else 
        {
            ans%=mod;
            printf("%lld\n",ans);
        }
    }
    
    return 0;
}
