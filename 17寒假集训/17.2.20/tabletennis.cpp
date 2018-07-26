#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	__int64 a,b,k;
	while (~scanf("%I64d%I64d%I64d",&k,&a,&b)) {
		if (a < b) {
			int temp = a;
			a = b;
			b = temp;
		}
		if (a < k && b < k) {
			printf("-1\n");
		} else {
			if (a % k && b < k) {
				printf("-1\n");
			} else {
				__int64 ans = a/k + b/k;
				printf("%I64d\n",ans);
			}
		}
	}
	return 0;
}
