#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 500 + 10;
int n, k, flag;
vector<int> g[MAX];

int dfs(int x)
{
    int ret = 1;
    if (!flag) {
        return 0;
    }
    for (int i = 0; i < g[x].size(); i ++) {
        ret += dfs(g[x][i]);
        if (!flag) {
            return 0;
        }
    }
    if (ret > 2) {
        flag = 0;
        return 0;
    }
    return ret & 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &k);
        int fa;
        flag = 1;
        for (int i = 1; i <= n; i ++) {
            g[i].clear();
        }
        for (int i = 2; i <= n; i ++) {
            scanf("%d", &fa);
            g[fa].push_back(i);
        }
        if (n & 1 || n / 2 - 1 > k) {
            puts("Alice");
            continue;
        }
        dfs(1);
        if (flag) {
            puts("Bob");
        } else {
            puts("Alice");
        }
    }
    return 0;
}
