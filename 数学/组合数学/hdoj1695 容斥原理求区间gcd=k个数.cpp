#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

int b,d,k;
vector<int> prime[100010];

int main()
{
	for (int i = 2; i < 100010; i += 2)
		prime[i].push_back(2);
	for (int i = 3; i < 100010; i += 2) {
		if (prime[i].size() == 0) {
			for (int j = i; j < 100010; j += i) {
				prime[j].push_back(i);
			}
		}
	}
		
	int t, tc = 1;
	scanf("%d",&t);
	while (t --) {
		scanf("%*d%d%*d%d%d",&b,&d,&k);
		printf("Case %d: ",tc ++);
		if (k == 0) {
			puts("0");
			continue;
		}
		if (b > d) {
			swap(b,d);
		}
		b /= k;
		d /= k;
		long long ans = 0;
		for (int i = 1; i <= d; i ++) {
			int n = min(i, b);
			ans += n;
			for (int ii = 1; ii < (1 << prime[i].size()); ii ++) {
				int cnt = 0;
				int mul = 1;
				for (int j = 0; j < prime[i].size(); j ++) {
					if (ii & (1 << j)) {
						++ cnt;
						mul *= prime[i][j];
					}
				}
				if (cnt & 1) {
					ans -= n / mul;
				} else {
					ans += n / mul;
				}
			}
		}		
		printf("%lld\n",ans);
	}
	return 0;
}
