#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
const int MAX = 110;

int main()
{
    int n,m, a[MAX][MAX];
    cin >> n >> m;
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < n; i ++) {
        sort(a[i], a[i] + m);
    }
    int maxx = -1;
    for (int i = 0; i < n; i ++) {
        maxx = max(maxx, a[i][0]);
    }
    cout << maxx << endl;
    return 0;
}

