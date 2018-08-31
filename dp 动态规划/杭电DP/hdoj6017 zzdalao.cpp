#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;

int DP[105][55][105];
char str[105];
int n,m;
int now=0,pos[105];
 
inline void solve(int T){
    memset(DP,-1,sizeof(DP));
    scanf("%d%d",&n,&m);m/=2;
    scanf("%s",str+1);
    now=0;
	for (int i=1;i<=n;i++) 
		if (str[i]=='2') pos[++now]=i;
    DP[0][m][0]=0;
    for (int i=1;i<=now;i++)
    for (int j=0;j<=m;j++)
    for (int k=0;k<=n;k++){
        if (DP[i-1][j][k]==-1) continue;
        for (int p=k+1;p<=n;p++){
            if (j<abs(pos[i]-p)) continue;
            int nxtJ=j-abs(pos[i]-p);
            if (p+2<=n) 
                DP[i][nxtJ][p+2]=max(DP[i][nxtJ][p+2],DP[i-1][j][k]+1);
            DP[i][nxtJ][p]=max(DP[i][nxtJ][p],DP[i-1][j][k]);
        }
    }
    
 
    int Ans=0;
    for (int j=0;j<=m;j++)
        for (int k=0;k<=n;k++)
            Ans=max(DP[now][j][k],Ans);
 
    printf("%d\n",Ans);
}
 
int main(){
    //freopen("in.txt","r",stdin);
    int T=0;
    scanf("%d",&T);
    for (int i=1;i<=T;i++)
        solve(i);
    return 0;
}
