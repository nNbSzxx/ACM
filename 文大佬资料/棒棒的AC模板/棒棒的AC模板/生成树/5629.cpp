#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
#define mod 1000000007ll
#define maxn 55
int T,n,a[maxn];
ll C[maxn][maxn],dp[maxn][maxn][maxn];
void init()
{
    memset(C,0,sizeof(C));
    C[0][0]=1;
    for(int i=1;i<=50;i++)
    {
        C[i][0]=C[i][i]=1;
        for(int j=1;j<i;j++)C[i][j]=(C[i][j-1]+C[i-1][j-1])%mod;
    }
}
int main()
{
    init();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%d",&a[i]);
        memset(dp,0,sizeof(dp));
        dp[0][0][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                for(int k=0;k<=n-2;k++)
                {
                    dp[i][j][k]=(dp[i][j][k]+dp[i-1][j][k])%mod;
                    for(int d=0;d<a[i]&&k+d<=n-2;d++)
                        dp[i][j+1][k+d]=(dp[i][j+1][k+d]+C[k+d][d]*dp[i-1][j][k]%mod)%mod;
                }
        printf("%d",n);
        for(int i=2;i<=n;i++)printf(" %I64d",dp[n][i][i-2]);
        printf("\n");
    }
    return 0;
}
