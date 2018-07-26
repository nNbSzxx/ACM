#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	int ans = 0;
	while (~scanf("%d",&n)) {
		if (n < 4) {
			if (n == 2) {
				printf("1\n");
			}
			if (n == 3)
				printf("7\n");
			continue;
		}
		if (n & 1) printf("7"), n -= 3;
		for (int i = 1; i <= n / 2; i ++)
			printf("1");
		printf("\n");
	}
	return 0;
}
