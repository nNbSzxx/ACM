#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring> 
using namespace std;
#define MAXN 120010
const long long N = LONG_LONG_MAX/4;
long long MIN(long long A,long long B){
	return A<B?A:B;
}
long long MAX(long long A,long long B){
	return A>B?A:B;
}
struct data{
    int x,y,v;
	data(){}
    data(int _x,int _y,long long  _v){
        x=_x;y=_y;v=_v;
    }
    friend bool operator <(data x,data y){
        return x.v>y.v;
    }
};
long long K;
long long a[4];
long long mod;
long long f[MAXN][4];
priority_queue<data>q;
bool vis[MAXN][4];
void dijkstra(){
    q.push(data(0,1,0));
    while(!q.empty()){
        int x=q.top().x;
        int y=q.top().y;
        q.pop();
        if(vis[x][y]){
            continue ;
        }
        vis[x][y]=1;
        int nx=(x+a[y])%mod;
        int ny=(y+1)%4;
        if(f[x][y]+a[y]<f[nx][ny]){
            f[nx][ny]=f[x][y]+a[y];
            q.push(data(nx,ny,f[nx][ny]));
        }
        nx=((x+a[(y-1+4)%4])%mod+mod)%mod;
        ny=(y-1+4)%4;
        if(f[x][y]+a[(y-1+4)%4]<f[nx][ny]){
            f[nx][ny]=f[x][y]+a[(y-1+4)%4];
            q.push(data(nx,ny,f[nx][ny]));
        
		}
    }
}
long long ans;
long long cnt(long long A,long long B){
	long long C=A/B*B;
	if(C<A)C=C+B;
	return C;
}
int main(){
	freopen("1005.in","r",stdin);
	int T;
	scanf("%d",&T);
	while(T--){ 
	    scanf("%lld",&K);
		for(int i=0;i<4;i++){
		    scanf("%lld",&a[i]);
		}
		mod=2*MIN(a[0],a[1]);
		for(int i=0;i<mod;i++){
			for(int j=0;j<4;j++){
				f[i][j]=N;vis[i][j]=0;
			}
		}
		f[0][1]=0;
		dijkstra();
		ans=N;
		for(long long i=0;i<mod;i++){ 
			if(f[i][1]>=K)ans=MIN(ans,f[i][1]);
			else ans=MIN(ans,f[i][1]+cnt(K-f[i][1],mod));
		}
		printf("%lld\n",ans);
	}
    return 0;
}


