#include <bits/stdc++.h>
using namespace std;
const int MAX = 25;
int k, r;

int main()
{
	while (~scanf("%d%d", &k, &r)) {
		int p = pow(2, k);
		int weak = p - r;
		int strong = r - 1;
		double ans = 0;
		double temp1 = 0, temp2 = 1;
		for (int i = 1; ; i ++) {
			if (pow(2, i) - 1 > p - r) {
				ans += 1.0 * temp1 * (i - 1);
				break;
			}
			int lim = p - r - pow(2, i) + 2;
			for (int j = p - r, k = 1; j >= lim; j --, k ++) {
				temp2 *= 1.0 * j / (p - k);
			}
			if (i >= 2)
				ans += 1.0 * (i - 1) * (temp1 - temp2);
			temp1 = temp2;
			temp2 = 1;
		}
		printf("%.5f\n", ans);
	}
	return 0;
}
