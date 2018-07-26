#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    const int k = 20;
    int n = 20, m = 0, cur = 21;
    int div = 1;
    int g[210][210];
    memset(g, 0, sizeof g);
    while (div <= 20) {
        n += k / div;
        int p = 1;
        for (int i = cur; i < cur + k / div; i ++) {
            for (int j = p; j < p + div; j ++) {
                g[i][j] = g[j][i] = 1;
                ++ m;
            }
            p += div;
        }
        cur += k / div;
        ++ div;
    }
    printf("%d %d\n", n, m);
    //int cnt = 0;
    for (int i = 1; i <= n; i ++) {
    	for (int j = i + 1; j <= n; j ++) {
    		if (g[i][j]) {
    			printf("%d %d\n", i, j);
    			//++ cnt;
			}
		}
	}
	//printf("%d\n", cnt);
	puts("20");
	for (int i = 1; i <= 20; i ++) {
		printf("%d\n", i);
	}
	return 0;
}
