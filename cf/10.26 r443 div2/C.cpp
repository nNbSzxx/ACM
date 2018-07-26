#include <bits/stdc++.h>
using namespace std;
const int MAX = 5e5 + 10;
int zero, one;
int n, x;
char c;

int main()
{
	scanf("%d", &n);
	zero = 0; one = 0xffffffff;
	for (int i = 1; i <= n; i ++) {
		scanf(" %c %d", &c, &x);
		switch (c) {
			case '&':
				zero &= x;
				one &= x;
				break;
			case '|':
				zero |= x;
				one |= x;
				break;
			case '^':
				zero ^= x;
				one ^= x;
				break;
		}
	}
	int andd = 0, orr = 0, xorr = 0;
	// 0->0 1->0 x&0|0^0
	// 0->0 1->1 x&1|0^0
	// 0->1 1->0 x&1|0^1
	// 0->1 1->1 x&1|1^0
	for (int i = 0; i < 10; i ++) {
		if (zero & (1 << i)) {
			if (one & (1 << i)) {
				andd |= (1 << i);
				orr |= (1 << i);
			} else {
				andd |= (1 << i);
				xorr |= (1 << i);
			}
		} else {
			if (one & (1 << i)) {
				andd |= (1 << i);
			} else {
				;
			}
		}
	}
	printf("3\n");
	printf("& %d\n", andd);
	printf("| %d\n", orr);
	printf("^ %d\n", xorr);
	return 0;
}
