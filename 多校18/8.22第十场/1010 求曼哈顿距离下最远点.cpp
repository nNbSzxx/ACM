#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const long long INF = 5e9 + 10;
const int MAX = 1e5 + 10;
int n, m, k;
long long a[MAX][6], b[MAX][6];

int main()
{
	int t;
    scanf("%d", &t);
    while (t --) {
		scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i ++) {
            for (int j = 0; j <= k; j ++) {
                scanf("%lld", &a[i][j]);
            }
        }
        for (int i = 1; i <= m; i ++) {
            for (int j = 0; j <= k; j ++) {
                scanf("%lld", &b[i][j]);
            }
            b[i][0] = -b[i][0];
        }
        ++ k;
        long long ans = -INF;
        long long maxa = -INF, mina = INF;
        long long maxb = -INF, minb = INF;
        for (int mask = 0; mask < (1 << k); mask ++) {
        	maxa = maxb = -INF;
        	mina = minb = INF;
	        for (int i = 1; i <= n; i ++) {
	        	long long tmp = 0;
	        	for (int j = 0; j < k; j ++) {
	        		if ((mask >> j) & 1) {
	        			tmp += a[i][j];
					} else {
						tmp -= a[i][j];
					}
				}
				maxa = max(maxa, tmp);
				mina = min(mina, tmp);
			}
			for (int i = 1; i <= m; i ++) {
				long long tmp = 0;
				for (int j = 0; j < k; j ++) {
					if ((mask >> j) & 1) {
						tmp += b[i][j];
					} else {
						tmp -= b[i][j];
					}
				}
				maxb = max(tmp, maxb);
				minb = min(tmp, minb);
			}
			ans = max(ans, max(maxa - minb, maxb - mina));
		}
        printf("%lld\n", ans);
    }
    
    return 0;
}
