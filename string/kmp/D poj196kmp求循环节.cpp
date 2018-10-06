#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1000005;
int nt[MAX];
char s[MAX];

int main()
{
	int n;

	int tc = 1;
	while (scanf("%d",&n), n) {
		scanf("%s",s);
		nt[0] = -1;
		int i = 0;
		int j = -1;
		while (i < n) {
			if (j == -1 || s[i] == s[j]) {
				nt[++ i] = ++ j;
			} else {
				j = nt[j];
			}
		}
		if (tc > 1) printf("\n");
		printf("Test case #%d\n",tc ++);
		for (int i = 2; i <= n; i ++) {
			if (i % (i - nt[i]) == 0 && nt[i] != 0) {
				printf("%d %d\n",i,i / (i - nt[i]));
			}
		}
	}
	return 0;
}
