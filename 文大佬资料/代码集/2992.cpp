#include<bits/stdc++.h> 
using namespace std;  
const int maxn=500;  
int cnt[maxn][maxn];  
int n,m;  
void cal(int t,int tmp)  {  
    int tt=t;  
    for(int i=2;t!=1;i++)  {  
        while(t%i==0) cnt[tt][i]+=tmp,t/=i;  
    }  
}  
int main(){  
//    freopen("in.txt","r",stdin);  
    for(int i=1;i<=450;i++)  
    cal(i,1);  
    for(int k=1;k<=450;k++)  
    for(int i=1;i<=450;i++)  
    cnt[k][i]+=cnt[k-1][i];  
    while(scanf("%d%d",&n,&m)!=EOF){  
        long long ans=1;  
        for(int i=1;i<=n;i++)  
        ans*=cnt[n][i]-cnt[n-m][i]-cnt[m][i]+1;  
        cout<<ans<<endl;  
    }  
    return 0;  
}  
