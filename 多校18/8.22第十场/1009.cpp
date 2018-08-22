#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#include <bits/stdc++.h>

using namespace std;

const int MAXN = 2e7 + 5;
long long phi[MAXN], ans[MAXN];
int vis[MAXN], prime[MAXN], cnt;

void init()
{
	memset(vis, 0, sizeof vis);
	cnt = 0;
	phi[1] = 1;
	for (int i = 2; i < MAXN; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < cnt; j ++) {
			if (1LL * i * prime[j] >= MAXN) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = prime[j] * phi[i];
				break;
			} else {
				phi[i * prime[j]] = (prime[j] - 1) * phi[i];
			}
		}
	}

	ans[0] = 0;
	for (int i = 1; i < MAXN; i ++) {
        if (i & 1) {
            ans[i] = ans[i - 1] + phi[i] / 2;
        } else {
            ans[i] = ans[i - 1] + phi[i];
        }
	}

}

int main()
{
    init();
    /*
    ios::sync_with_stdio(false);
    int sum = 0;
    int last = 0;
    for (int n = 1; n <= 233; n++)
    {
        sum = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= i - 1; j++)
                if (__gcd(i + j, i - j) == 1)
                    sum++;
        cout << n  << " " << sum << " " << sum - last << " " << phi[n] << endl;
        last = sum;
    }
    */

    int t;
    scanf("%d", &t);
    while (t --) {
        int id;
        scanf("%d", &id);
        printf("%lld\n", ans[id]);
    }

    return 0;
}



