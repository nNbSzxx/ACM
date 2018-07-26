#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	while (~scanf("%d%d",&m,&n)) {
		if (m % (n + 1) == 0) {
			puts("none");
			continue;
		}
		if (n >= m) {
			printf("%d",m);
			for (int i = m + 1; i <= n; i ++) {
				printf(" %d",i);
			}
			printf("\n");
			continue;
		}
		printf("%d\n",m % (n + 1));
	}
	return 0;
}
