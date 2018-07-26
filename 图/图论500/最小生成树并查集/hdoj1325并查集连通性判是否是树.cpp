#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 100005;
int father[MAX];
int find(int x)
{
    while (x != father[x]) {
        father[x] = father[father[x]];
        x = father[x];
    }
    return x;
}
void unite(int a, int b)
{
    a = find(a);
    b = find(b);
    father[a] = b;
    return ;
}
int main()
{
    int x,y,visit[MAX],tc = 0,degree[MAX];
    while (scanf("%d%d",&x,&y), x >= 0 && y >= 0) {
        for (int i = 1; i <= 100000; i ++) {
            father[i] = i;
        }
        memset(visit,0,sizeof(visit));
        memset(degree,0,sizeof(degree));
        if (x && y) {
            unite(x, y);
            degree[y] ++;
            visit[x] = visit[y] = 1;
        } else {
            printf("Case %d is a tree.\n",++ tc);
            continue;
        }
        int flag = 1;
        while (scanf("%d%d",&x,&y), x || y) {
            visit[x] = visit[y] = 1;
            degree[y] ++;
            int xx = find(x);
            int yy = find(y);
            if (flag) {
                if (xx == yy) {
                    flag = 0;
                } else {
                    unite(x,y);
                }
                if (degree[y] > 1) {
                    flag = 0;
                }        
            }
        }
        int cnt = 0;
        if (flag) {
            for (int i = 1; i <= 100000; i ++) {
                if (visit[i] && i == father[i]) {
                    cnt ++;
                }
            }
            if (cnt != 1) {
                flag = 0;
            }
        } 
        if (flag) {
            printf("Case %d is a tree.\n",++ tc);
        } else {
            printf("Case %d is not a tree.\n",++ tc);
        }
    }
    return 0;
}
