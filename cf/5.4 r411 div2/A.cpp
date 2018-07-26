#include <cstdio>
using namespace std;

int main()
{
	int l,r;
	while (~scanf("%d%d",&l,&r)) {
		int d = l - r;
		if (d == 0) {
			printf("%d\n",l);
			continue;
		}
		if (d == 1 || d == 2) {
			puts("2");
			continue;
		}
		if (d == 3) {
			if (l & 1) {
				puts("3");
			} else {
				puts("2");
			}
			continue;
		}
		puts("2");
	}
	return 0;
}
