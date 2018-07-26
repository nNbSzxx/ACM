#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e6 + 10;
long long phi[MAX];

void init()
{
	memset(phi, 0, sizeof phi);
	phi[1] = 1;
	for (int i = 2; i < MAX; i ++) {
		if (!phi[i]) {
			phi[i] = i - 1;
			for (int j = 2 * i; j < MAX; j += i) {
				if (!phi[j])
					phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

void getsum()
{
	phi[0] = 0;
	for (int i = 1; i < MAX; i ++) {
		phi[i] += phi[i - 1];
	}
}

int main()
{
	init();
	getsum();
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		printf("%lld\n", phi[b] - phi[a - 1]);
	}
}

