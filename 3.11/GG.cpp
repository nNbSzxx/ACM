#include<stdio.h>  
#include<algorithm>  
#include<math.h>  
#define P sqrt(2)  
using namespace std;  
double dp[1007][1007];  
struct N  
{  
    int x,y;  
}p[107];  
int cmp(N a,N b)  
{  
    if(a.x==b.x)return a.y<b.y;  
    return a.x<b.x;  
}  
int main()  
{  
    int n,m;  
    while(scanf("%d%d",&n,&m)!=EOF)  
    {  
        n++;m++;  
        int k;  
        scanf("%d",&k);  
        for(int i=0;i<k;i++)  
            scanf("%d%d",&p[i].x,&p[i].y);  
        sort(p,p+k,cmp);  
        dp[1][1]=0;  
        for(int i=2;i<=n;i++)
            dp[i][1]=dp[i-1][1]+1;  
        for(int i=2;i<=m;i++) 
            dp[1][i]=dp[1][i-1]+1;  
        for(int i=2;i<=n;i++)  
            for(int j=2;j<=m;j++)  
            {  
                int flag=0;  
                for(int a=0;a<k;a++)  
                    if(p[a].x==(i-1)&&p[a].y==(j-1)) 
                        {dp[i][j]=min(dp[i-1][j]+1,min(dp[i][j-1]+1,dp[i-1][j-1]+P));flag=1;break;}  
                    else if(p[a].x>(i-1))break;  
                if(!flag)dp[i][j]=min(dp[i-1][j]+1,dp[i][j-1]+1); 
            }  
        printf("%.lf\n",dp[n][m]*100);  
    }  
    return 0;  
} 
