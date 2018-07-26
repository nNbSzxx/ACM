#include <bits/stdc++.h>
using namespace std;
const int maxn = 2005;
int n, m;
struct node {
    int x, y, left;
    const bool operator > (const node b) {
        return this->left > b.left;
    }
};
stack<node> s;
int c[maxn][maxn], x[maxn][maxn], y[maxn][maxn], up[maxn];
int ans1 = 0, ans2 = 0;
void solve1() {
    for(int j = 1; j <= m; j++) {
        memset(up, -1, sizeof(up));
        for(int i = 1; i <= n; i++) {
            node a = (node){i, j, x[i][j]};
            node b =(node){0, j, 0}; 
            if(!s.empty()){
                b = s.top();
                while(b > a) {
                s.pop();
                ans2 = max(ans2, (a.x - up[b.x]) * b.left);
                ans1 = max(ans1, min(b.left, a.x - up[b.x]) * min(b.left, a.x-up[b.x])); 
                if(s.empty()){
                   b = (node){0, j, 0};
                    break;
                } 
                b = s.top();
            }
            } 
            up[a.x] = b.x+1;
            s.push(a);
        }
        while(!s.empty()) {
            node a = s.top();
            s.pop();
            ans2 = max(ans2, (n+1 - up[a.x]) * a.left);
            ans1 = max(ans1, min(a.left, n - up[a.x] + 1) * min(a.left, n-up[a.x]+1)); 
        }
    }
}
void solve2() {
    for(int j = 1; j <= m; j++) {
        memset(up, -1, sizeof(up));
        for(int i = 1; i <= n; i++) {
            node a = (node){i, j, y[i][j]};
            node b =(node){0, j, 0}; 
            if(!s.empty()){
                b = s.top();
                while(b > a) {
                s.pop();
                ans2 = max(ans2, (a.x - up[b.x]) * b.left);
                ans1 = max(ans1, min(b.left, a.x - up[b.x]) * min(b.left, a.x-up[b.x]));
                if(s.empty()){
                   b = (node){0, j, 0};
                    break;
                } 
                b = s.top();
            }
            } 
            up[a.x] = b.x+1;
            s.push(a);
        }
        while(!s.empty()) {
            node a = s.top();
            s.pop();
            ans2 = max(ans2, (n - up[a.x] + 1) * a.left);
            ans1 = max(ans1, (min(a.left, (n-up[a.x]+1)) * min(a.left, (n-up[a.x]+1))));
        }
    }
}


int main() {
    //freopen("input", "r", stdin);
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            scanf("%d", &c[i][j]);
            if((i+j)%2==1) {
                c[i][j] ^= 1;
            }
            x[i][j] = c[i][j] == 1?x[i][j-1]+1:0;
            y[i][j] = c[i][j] == 0?y[i][j-1]+1:0;
        }
    }
    solve1();
    solve2();
    printf("%d\n%d", ans1, ans2);
}
