#include <cstdio>
using namespace std;

int main()
{
	int t,n,k,tc = 1;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&k);
		printf("Case %d: ", tc ++);
		if (k == 1) {
			if (n & 1) {
				puts("first");
			} else {
				puts("second");
			}
			continue;
		}
		if (k >= n) {
			puts("first");
			continue;
		}
		puts("second");
	}
} 
