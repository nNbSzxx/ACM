#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int M = 1e+6+10;
long long di[M],sd[M];
int vis[M],phi[M],prime[M],mark[M];
void getphi(){
    long long i,j;
    phi[1]=1;
    int tot=0;
    for(i=2;i<M;i++)//相当于分解质因式的逆过程
    {
         if(!mark[i])  {
                 prime[++tot]=i;//筛素数的时候首先会判断i是否是素数。
                 phi[i]=i-1;//当 i 是素数时 phi[i]=i-1
        }
         for(j=1;j<=tot;j++)  {
             if(i*prime[j]>M)  break;
             mark[i*prime[j]]=1;//确定i*prime[j]不是素数
             if(i%prime[j]==0)//接着我们会看prime[j]是否是i的约数
             {
                 phi[i*prime[j]]=phi[i]*prime[j];break;
             }
             else  phi[i*prime[j]]=phi[i]*(prime[j]-1);//其实这里prime[j]-1就是phi[prime[j]]，利用了欧拉函数的积性
         }
    }
}


long long div(){
    for(int i=1;i<M;i++){
        int tmp=1,pt=0;
        int ti=i;
        for(int j=1;prime[j]*prime[j]<=i;j++){

            int ct=1;
            if(ti%prime[j]==0) pt++;
            while(ti%prime[j]==0) ti=ti/prime[j],ct++;
            tmp=tmp*ct;
        }
        if(ti>1) tmp=tmp*2,pt++;
        di[i]=tmp;
        vis[i]=pt;
    }
    return 0;
}

long long cnt(){
    long long sum=1;
    sd[1]=1;
    for(int i=2;i<M;i++){
        sum=sum+di[i-1]+1;
        sd[i]=sd[i-1]+sum;
    }

    return sum;
}

int main(){
    getphi();
    div();
    cnt();
    int n;
    while(cin>>n){
        long long ans=sd[n];
        for(int i=2;i<=n;i++){
            if(vis[i]==1&&mark[i]) continue;
            if(vis[i]&1){
                ans=ans-sd[n/i];
            }
            else ans=ans+sd[n/i];
        }
        cout<<ans<<endl;
    }
}
