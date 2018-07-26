#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
long long n;
std::vector<std::pair<int, int> > ans;

int main()
{
	while (~scanf("%lld", &n)) {
		ans.clear();
		int bound = sqrt(n) + 1;
		int i = 1, j = 1;
		long long sum = 0;
		while (true) {
			if (sum < n) {
				if (j > bound) {
					break;
				}
				sum += 1LL * j * j;
				++ j;
			} else if (sum > n) {
				sum -= 1LL * i * i;
				++ i;
			}
			if (sum == n) {
				ans.push_back(std::make_pair(i, j));
				sum -= 1LL * i * i;
				++ i;
			}
			
		}
		printf("%d\n", ans.size());
		for (int i = 0; i < ans.size(); i ++) {
			std::pair<int, int> p = ans[i];
			printf("%d", p.second - p.first);
			for (int i = p.first; i < p.second; i ++) {
				printf(" %d", i);
			}
			puts("");
		}
	}
	return 0;
}
