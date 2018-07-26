#include <bits/stdc++.h>
using namespace std;
const int MAXA = 1e4 + 52;
const int MAXT = 1e3 + 10;
const int MAXS = 52;
int up[MAXS];
vector<int> down[MAXS];
int n, m;
int deal[MAXA][MAXS];
int state[MAXS], dep[MAXS];
map<char, int> mp;
queue<int> qs, qt;

void upscan(int u, int v, int tme)
{
    if (u == 0)
        return ;
    if (down[u][0] == v) {
        deal[tme][u] = 0;
    } else {
        deal[tme][u] = 1;
    }
    upscan(up[u], u, tme - 1);
}

void downscan(int u, int d)
{
    dep[u] = d;
    if (down[u].size() == 0) {
        return ;
    }
    if (down[u].size() == 1) {
        state[u] = 0;
        downscan(down[u][0], d + 1);
    }
    // 2
    downscan(down[u][0], d + 1);
    downscan(down[u][1], d + 1);
}

int main()
{
    freopen("instruction.in", "r", stdin);
    freopen("instruction.out", "w", stdout);
    memset(deal, -1, sizeof deal);
    scanf("%d", &n);
    char c, fa, v;
    for (int i = 1; i <= n; i ++) {
        scanf(" %c", &c);
        if (c == 's') {
            scanf("%d", &fa);
            up[i] = fa;
            down[fa].push_back(i);
        } else { // p
            scanf("%d %c", &fa, &c);
            up[i] = fa;
            down[fa].push_back(i);
            mp[c] = i;
        }
    }
    downscan(1, 1);
    for (int i = 1; i <= n; i ++) {
        if (down[i].size() != 0) {
            if (down[i][0] < down[i][1]) {
                state[i] = 0;
            } else {
                state[i] = 1;
            }
        }
    }
    scanf("%d", &m);
    int a;
    for (int i = 1; i <= m; i ++) {
        scanf("%d %c", &a, &c);
        int id = mp[c];
        upscan(up[id], id, a + dep[up[id]]);
    }
    for (int i = 1; i < MAXA; i ++) {
        for (int j = 1; j < MAXS; j ++) {
            if (deal[i][j] != -1 && state[j] != deal[i][j] ) {
                state[j] = deal[i][j];
                qs.push(j);
                qt.push(i);
            }
        }
    }
    printf("%d\n", qs.size());
    while (!qs.empty()) {
        printf("%d %d\n", qs.front(), qt.front());
        qs.pop(); qt.pop();
    }
    return 0;
}
