#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int main()
{
	int t,n,m;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		__int64 sum = 0;
		int temp;
		for (int i = 0; i < n; i ++) {
			scanf("%d",&temp);
			sum += temp;
		}
		__int64 q;
		for (int i = 0; i < m; i ++) {
			scanf("%I64d",&q);
			if (q <= sum) {
				printf("0");
			} else {
				printf("1");
			}
		}
		printf("\n");
	}
	return 0;
}
