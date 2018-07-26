#include <cstdio>
using namespace std;

int main()
{
	int n;
	char s[2] = {'a','b'};
	while (~scanf("%d",&n)) {
		int loc = 0;
		for (int i = 1; i <= n; i ++) {
			if (i & 1) {
				if (loc == 0) {
					loc = 1;
				} else {
					loc = 0;
				}
			}
			printf("%c",s[loc]);
		}
		printf("\n");
	}
	return 0;
}
