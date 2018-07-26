#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX= 1e5 + 10;
const int mod = 1e9 + 9;
long long sum;
int father[MAX * 2];
long long int cnt[MAX * 2];

int find(int x)
{
    while (x != father[x]) {
        father[x] =father[father[x]];
        x = father[x];
    }
    return x;
}

void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) {
        father[x] = y;
        return ;
    } else {
        sum = (sum * 2 + 1) % mod;
    }
}

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
        cnt[i] = 0;
    }
    int a, b;
    for (int i = 1; i <= m; i ++) {
        scanf("%d%d", &a, &b);
        merge(a, b);
        printf("%lld\n", sum);
    }
    return 0;
}

