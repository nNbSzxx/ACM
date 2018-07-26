#include<bits/stdc++.h> 
using namespace std;
const int M =1405;
int n,s;
int map[M][M],vis[M],link[M];
int dfs(int t){
    for(int i=1;i<=n;i++){
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
        if(dfs(i))num++;
    }
    return num;
}
int main(){
	freopen("A.in","r",stdin);
    int a,b;
    while(cin>>n){
        for(int i=1;i<=n;i++)
        	for(int j=1;j<=n;j++)
        		map[i][j]=0;
        for(int i=1;i<=n;i++){
			scanf("%d: (%d)",&a,&s);
			a++;
			//printf("%d %d\n",a,s);
			for(int j=1;j<=s;j++){
				scanf("%d",&b);
				b++;
				map[a][b]=1;
				map[b][a]=1;
			} 
		}
		
        cout<<(n+n-MaxMatch())/2<<endl;
    }
    return 0;
}

