#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e4 + 10;
int father[MAX];

int find(int x)
{
    while (x != father[x]) {
        father[x] = father[father[x]];
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
    }
    return ;
}
int main()
{
    int n;
    cin >> n;
    int a;
    for (int i = 1; i <= n; i ++) {
        father[i] = i;
    }
    for (int i = 1; i <= n; i ++) {
        cin >> a;
        merge(i, a);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i ++) {
        if (father[i] == i) {
            cnt ++;
        }
    }
    cout << cnt << endl;
    return 0;
}
