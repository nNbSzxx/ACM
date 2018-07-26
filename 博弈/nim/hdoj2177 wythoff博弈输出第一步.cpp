#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int a,b;
	while (~scanf("%d%d",&a,&b), a || b) {
		if (a > b) {
			swap(a, b);
		}
		int k = b - a;
		int aa = int(1.0 * (sqrt(5) + 1) / 2.0 * k);
		if (aa == a) {
			puts("0");
			continue;
		} else {
			puts("1");
		}
		if (aa < a)
			printf("%d %d\n", aa, aa + k);
		for (int i = a - 1; i >= 1; i --) {
			int del = (sqrt(5) + 1) / 2.0 * (b - i);
			if (del == i) {
				printf("%d %d\n", i, b);
				break;
			} else {
				if (del > i) {
					break;
				}
			}
		}
		for (int i = b - 1; i >= 1; i --) {
			int aa = a; int bb = i;
			if (aa > bb) {
				swap(aa, bb);
			}
			int del = (sqrt(5) + 1) / 2.0 * (bb - aa);
			if (del == aa) {
				printf("%d %d\n", aa, bb);
				break;
			} 
		}
	}
}
