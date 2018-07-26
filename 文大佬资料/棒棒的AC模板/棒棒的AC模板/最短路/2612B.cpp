#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring> 
using namespace std;
#define MAXN 50010
#define MAXM 1010

struct data{
    int x;
    int v;
    data(){
         
    }
    data(int _x,int _v){
        x=_x;
        v=_v;
    }
    friend bool operator <(data x,data y){
        return x.v>y.v;
    }
};
int n;
int a[MAXN];
int mn;
int f[MAXN];
priority_queue<data>q;
bool vis[MAXN];
void dijkstra(){
    int i,x;
    memset(f,0x3f,sizeof(f));
    f[0]=0;
    q.push(data(0,0));
    while(!q.empty()){
        x=q.top().x;
        q.pop();
        if(vis[x]){
            continue ;
        }
        vis[x]=1;
        for(i=1;i<=n;i++){
            if(f[x]+a[i]<f[(x+a[i])%mn]){
                f[(x+a[i])%mn]=f[x]+a[i];
                q.push(data((x+a[i])%mn,f[(x+a[i])%mn]));
            }
        }
    }
}
int main(){
    int i,j,x;
    scanf("%d",&n);
    for(i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    mn=a[1];
    dijkstra();
    scanf("%d",&n);
    while(n--){
        scanf("%d",&x);
        printf(x>=f[x%mn]?"TAK\n":"NIE\n");
    }
    return 0;
}


