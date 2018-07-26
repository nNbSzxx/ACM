#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 8010;

int main()
{
	int n2[5];
	int a[MAX], b[MAX];
	while (~scanf("%d%d%d",&n2[1],&n2[2],&n2[3]), n2[1] || n2[2] || n2[3]) {
		memset(a, 0, sizeof(a));
		int bound = n2[1] + n2[2] * 2 + n2[3] * 5 + 1;
		a[0] = 1;
		for (int i = 1; i <= 3; i ++) {
			memset(b, 0 ,sizeof(b));
			int step = 5;
			if (i == 1) step = 1;
			if (i == 2) step = 2;
			for (int j = 0; j <= bound && j <= n2[i] * step; j += step) {
				for (int k = 0; k + j <= bound; k ++) {
					b[j + k] += a[k];
				}
			}
			memcpy(a, b, sizeof(b));
		}
		for (int i = 1; i <= bound ; i ++) {
			if (a[i] == 0) {
				printf("%d\n",i);
				break;
			}
		} 
	}
	return 0;
}
