#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000 + 10;
int mp[100001][251];
int a[MAX];
int n, k, p;

int dfs(int p, int k)
{
    if (p > n) return 0;
    if (mp[p][k] != -1) return mp[p][k];
    return mp[p][k] = dfs(p + a[p] + k, k) + 1;
}

int main()
{
    memset(mp, -1, sizeof(mp));
    cin >> n ;
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    int q;
    cin >> q;
    for (int i = 1; i <= q; i ++) {
        cin >> p >> k;
        if (k > 250) {
            int times = 0;
            while (p <= n) {
                times ++;
                p = a[p] + k + p;
            }
            cout << times << endl;
            continue;
        }
        cout << dfs(p, k) << endl;
    }
    return 0;
}


