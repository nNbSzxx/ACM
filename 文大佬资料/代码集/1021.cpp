//以一个快中每两点距离作为hash值 
#include <cstdio>
#include <algorithm>

const int MAXN=111;

using namespace std;

void inputmap(int n, bool map[][MAXN]){
    for(int i=0; i<n; ++i){
        int x, y;
        scanf("%d%d", &x, &y);
        map[x][y]=true;
    }
}
void solve(bool map[][MAXN], int w, int h, int *st, int &top){
    bool vis[MAXN][MAXN]={false};
    for(int i=0; i<w; ++i){
        for(int j=0; j<h; ++j){
            if(!map[i][j] || vis[i][j]) { continue; }
            vis[i][j]=true;
            int head=0, tail=1;
            int qx[MAXN]={i}, qy[MAXN]={j};
            while(head!=tail){
                int x=qx[head], y=qy[head]; ++head;
                const int xx[4]={-1,0,1,0};
                const int yy[4]={0,-1,0,1};
                for(int i=0; i<4; ++i){
                    int dx=x+xx[i], dy=y+yy[i];
                    if(dx<0 || dx>=w || dy<0 || dy>=h) { continue; }
                    if(!map[dx][dy] || vis[dx][dy]) { continue; }
                    qx[tail]=dx; qy[tail]=dy; ++tail;
                    vis[dx][dy]=true;
                }
            }
            int hash=0;
            for(int i=0; i<tail; ++i){
                for(int j=i+1; j<tail; ++j){
                    int x=qx[i]-qx[j];
                    int y=qy[i]-qy[j];
                    hash += x*x+y*y;
                }
            }
            st[top++]=hash;
        }
    }
}

int main(){
    int t;
    for(scanf("%d", &t); t; --t){
        bool map1[MAXN][MAXN]={false};
        bool map2[MAXN][MAXN]={false};
        int W, H, n;
        scanf("%d%d%d", &W, &H, &n);
        inputmap(n, map1);
        inputmap(n, map2);
        int top1=0, top2=0;
        int st1[MAXN*MAXN];
        int st2[MAXN*MAXN];
        solve(map1, W, H, st1, top1);
        solve(map2, W, H, st2, top2);     
        bool flag=false;
        if(top1==top2){
            flag=true;
            int top=top1;
            sort(st1,st1+top);
            sort(st2,st2+top);
            for(int i=0; i<top; ++i){
                if(st1[i]!=st2[i]){
                    flag=false;
                    break;
                }
            }
        }
        if(flag){ printf("YES\n"); }
        else { printf("NO\n"); }
    }
    return 0;
}

