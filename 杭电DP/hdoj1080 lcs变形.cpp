#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 105;

int val(char x, char y) {
    if(y != '-' && x > y) swap(x, y);
    if(x == 'A') {
        if(y == 'A') return 5;
        if(y == 'C') return -1;
        if(y == 'G') return -2;
        if(y == 'T') return -1;
        return -3;
    }
    if(x == 'C') {
        if(y == 'C') return 5;
        if(y == 'G') return -3;
        if(y == 'T') return -2;
        return -4;
    }
    if(x == 'G') {
        if(y == 'G') return 5;
        if(y == 'T') return -2;
        return -2;
    }
    if(x == 'T') {
        if(y == 'T') return 5;
        return -1;
    }
}
int main()
{
	char a[110], b[110];
	int dp[110][110];
    int t; scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d%s", &n, a+1);
        scanf("%d%s", &m, b+1); 
		dp[0][0] = 0;
        for(int i = 1; i <= n; i++) {
            dp[i][0] = dp[i-1][0] + val(a[i], '-');
        }
        for(int i = 1; i <= m; i++) {
            dp[0][i] = dp[0][i-1] + val(b[i], '-');
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = max(dp[i-1][j-1] + val(a[i], b[j]), max(dp[i-1][j] + val(a[i], '-'), dp[i][j-1] + val(b[j], '-')));
            }
        }
        printf("%d\n", dp[n][m]);
    }
    return 0;
}
