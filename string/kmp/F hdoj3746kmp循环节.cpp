#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 100010;

int main()
{
	int nt[MAX];
	char s[MAX];
	int t;
	scanf("%d",&t);
	int len;
	while (t --) {
		scanf("%s",s);
		len = strlen(s);
		int i = 0, j = -1;
		nt[0] = -1;
		while (i < len) {
			if (j == -1 || s[i] == s[j]) {
				nt[++ i] = ++ j;
			} else {
				j = nt[j];
			}
		}
		int cir = len - nt[len];
		if (cir != len && len % cir == 0) {
			printf("0\n");
		} else {
			printf("%d\n",cir - len % cir);
		}
	}
	return 0;
}
