#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
int dis[MAX][MAX];
int n, ans = 0;

void fuck() {}

void readmp(int i, int j)
{
    //printf("%d %d\n", i, j);
    scanf("%d", &dis[i][j]);
    (i < n)
        ? readmp((j < n)? i : i + 1, (j < n)? j + 1: 1) // i < n
        : (j < n)     // i == n
            ? readmp(i, j + 1) // j < n
            : fuck();          // j == n

}

void floyd(int k, int i, int j)
{
    //printf("%d %d %d\n", k, i, j);
    dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
    (k < n)
        ? (i < n)
            ? (j < n)
                ? floyd(k, i, j + 1) // j < n
                : floyd(k, i + 1, 1) // j == n
        : (j < n)               // i == n
            ? floyd(k, i, j + 1) // j < n
            : floyd(k + 1, 1, 1) // j == n
        : (i < n)
            ? (j < n)
                ? floyd(k, i, j + 1) // j < n
                : floyd(k, i + 1, 1) // j == n
        : (j < n)               // i == n
            ? floyd(k, i, j + 1) // j < n
            : fuck(); // j == n

}

void findmin(int i, int j)
{
    //printf("%d %d\n", i, j);
    ans = max(ans, dis[i][j]);
    (i < n)
        ? findmin((j < n)? i : i + 1, (j < n)? j + 1: 1) // i < n
        : (j < n)     // i == n
            ? findmin(i, j + 1) // j < n
            : fuck();          // j == n
}

int main()
{
    scanf("%d", &n);
    readmp(1, 1);
    floyd(1, 1, 1);

    findmin(1, 1);
    printf("%d\n", ans);
    return 0;
}
