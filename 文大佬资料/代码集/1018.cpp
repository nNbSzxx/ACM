#include<bits/stdc++.h> 
using namespace std;
const int inf = 0x3f3f3f3f;
int dp[120][1200];

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1; i<=n; i++)  
        {
            for(int j=0; j<1100; j++)
                dp[i][j]=inf;
        }
        for(int i=1; i<=n; i++)  
        {
            int num;
            scanf("%d",&num);
            for(int j=1; j<=num; j++)
            {
                int p,b;
                scanf("%d%d",&b,&p);
                if(i==1)
                {
                    dp[1][b]=min(dp[1][b],p);
                }
                else
                {
                    for(int k=0; k<1100; k++)
                    {
                        if(dp[i-1][k]!=inf)
                        {
                            if(k<=b)
                                dp[i][k]=min(dp[i][k],dp[i-1][k]+p);
                            else
                                dp[i][b]=min(dp[i][b],dp[i-1][k]+p);
                        }
                    }
                }
            }
        }
        double ans=0;
        for(int i=0; i<1100; i++)
        {
            if(dp[n][i]!=inf)
            {
                double k=(double)i/dp[n][i];
                if(k>ans)
                    ans=k;
            }
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}

