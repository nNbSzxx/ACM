#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t,n,k;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&k);
		-- k;
		while (k -- && n > 0) {
			int i = 1;
			while ((1<<(i+1)) <= n) i ++;
			n -= 1 << i;
		}
		if (n <= 0) {
			printf("0\n");
			continue;
		} else {
			int i = 1;
			while ((1 << i) < n) i ++;
			printf("%d\n",(1<<i)-n);
		}
	}
	return 0;
}
