#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int one = (1 << 10) - 1;
	int zero = 0;
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		char c;
		int m;
		scanf(" %c%d", &c, &m);
		if (c == '&') {
			one &= m;
			zero &= m;
		} else if (c == '|') {
			one |= m;
			zero |= m;
		} else {
			one ^= m;
			zero ^= m;
		}
	}
	int andd = (1 << 10) - 1;
	int orr = 0;
	int xorr = 0;
	for (int i = 0; i < 10; i ++) {
		int onebit = (one >> i) & 1;
		int zerobit = (zero >> i) & 1;
		if (onebit == 0 && zerobit == 0) {
			andd ^= (1 << i);
		} else if (onebit == 1 && zerobit == 1) {
			orr ^= (1 << i);
		} else if (onebit == 0 && zerobit == 1) {
			xorr ^= (1 << i);
		}
	}
	printf("%d\n", 3);
	printf("| %d\n", orr);
	printf("& %d\n", andd);
	printf("^ %d\n", xorr);
	return 0;
}
