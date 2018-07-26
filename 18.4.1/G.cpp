#include <bits/stdc++.h>
using namespace std;
const int MAX = 100;
int f, it, t;
char c;
int mt[MAX][MAX];

int main()
{
    cin >> f >> it >> t;
    for (int i = 1; i <= f; i ++) {
        for (int j = 1; j <= it; j ++) {
            cin >> c;
            if (c == 'Y' )
                mt[i][j] = 1;
            else
                mt[i][j] = 0;
        }
    }
    int ans = 0;
    for (int i = 1; i <= it; i ++) {
        int sum = 0;
        for (int j = 1; j <= f; j ++) {
            if (mt[j][i])
                ++ sum;
        }
        if (sum >= t)
            ++ ans;
    }
    cout << ans << endl;
    return 0;
}
