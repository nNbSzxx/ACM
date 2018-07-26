#include<bits/stdc++.h> 
using namespace std;
#define maxm 405
//最大团=原图补图的最大独立集 
int n,m,s;
int map[maxm][maxm],vis[maxm],link[maxm];//map存图
int dfs(int t){
    for(int i=1;i<=m;i++){
        if(vis[i]==0&&map[t][i]){
            vis[i]=1;
            if(link[i]==-1||dfs(link[i])){
                link[i]=t;
                return 1;
            }
        }
    }
    return 0;
}
int MaxMatch(){
    int num=0;
    memset(link,-1,sizeof(link));
    for(int i=1;i<=n;i++){
        memset(vis,0,sizeof(vis));
        if(dfs(i))
        num++;
    }
    return num;
}
int main(){
    int a,b,cas=1;
    while(cin>>n>>m>>s){
        if(n==0&&m==0&&s==0)break;
        for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
        map[i][j]=1;
        for(int i=0; i<s; i++){
            cin>>a>>b;
            map[a][b]=0;
        }
        cout<<"Case "<<cas++<<": "<<n+m-MaxMatch()<<endl;
    }
    return 0;
}

