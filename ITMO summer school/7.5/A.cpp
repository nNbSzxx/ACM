#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1010;
int vis[MAX];
int ans[MAX];
int sum, flag, num, n;

void dfs(int x)
{
    if (sum == n) {
        flag = 1;
        num = x;
        return ;
    }
    if (flag) return ;
    for (int i = 1; i <= n; i ++) {
        if (!vis[i]) {
            vis[i] = 1;
            ans[x] = i;
            sum += i;
            dfs(x + 1);
            if (flag) return ;
            vis[i] = 0;
            sum -= i;
        }
    }
}

int main()
{
    cin >> n;
    memset(vis, 0, sizeof(vis));
    if (n == 0) {
        cout << 0 << endl;
        return 0;
    }
    flag = 0;
    sum = 1;
    vis[1] = 1;
    ans[0] = 1;
    dfs(1);
    cout << num << endl;
    cout << ans[0] ;
    for (int i = 1; i < num ; i++) {
        cout << " " << ans[i];
    }
    return 0;
}
