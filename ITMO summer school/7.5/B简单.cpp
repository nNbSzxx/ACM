
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX = 110;

int main()
{
    int n;
    int g[MAX][MAX];
    memset(g, 0 ,sizeof(g));
    cin >> n;
    int pos[MAX];
    int dis[MAX];
    for (int i = 1; i <= n; i ++) {
        cin >> pos[i] >> dis[i];
    }
    for (int i = 1; i <= n; i ++) {
        int att = pos[i] + dis[i];
        for (int j = 1; j <= n; j ++) {
            if (i != j) {
                if (att == pos[j]) {
                    g[i][j] = 1;
                }
            }
        }
    }
    int flag = 0;
    for (int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j ++) {
            if (g[i][j] && g[j][i]) {
                flag = 1;
                break;
            }
        }
    }
    if (flag) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}
