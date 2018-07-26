#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
long long vis[MAX], n;

inline int lowbit(int x)
{
    return (x) & (-x);
}

void add(int x, int v)
{
    while (x <= n) {
        vis[x] += v;
        x += lowbit(x);
    }
    return ;
}

long long query(int x)
{
    long long sum = 0;
    if (x == 0) return 0;
    while (x > 0) {
        sum += vis[x];
        x -= lowbit(x);
    }
    return sum;
}
int main()
{
    int k;
    cin >> n >> k;
    if (k > n / 2) {
        k = n - k;
    }
    memset(vis, 0, sizeof(vis));
    int i = 1, flag = 0;
    long long ans = 1;
    int cnt = 1;
    while (cnt <= n) {
        ++ cnt;
        int j = i + k;
        if (j > n) j -= n;
        if (j < i) {
            ans += query(n) - query(i) + query(j - 1) + 1;
        } else {
            ans += query(j - 1) - query(i) + 1;
        }
        add(i, 1);
        add(j, 1);

        i = j;
        if (flag) {
            cout << " ";
        }
        cout << ans;
        flag = 1;
    }
    return 0;
}
