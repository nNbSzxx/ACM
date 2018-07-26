#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 10009;
int main()
{
	int t;
	int nt[MAX];
	char s[MAX], w[MAX] = "tjmts";
	int i, j, len1;
	int lenw = strlen(w);
	i = 0;
	j = -1;
	nt[0] = -1;
	while (i < lenw) {
		if (j == -1 || w[i] == w[j]) {
			nt[++ i] = ++ j;
		} else {
			j = nt[j];
		}
	}
	scanf("%d",&t);
	while (t --) {
		int len;
		scanf("%d %s", &len, s);
		int ans = 0;
//		int len = strlen(s);
		int i = 0; j = 0;
		while (i < len) {
			if (s[i] == w[j] || j == -1) {
				i ++; j ++;
			} else {
				j = nt[j];
			}
			if (j == lenw) {
				ans ++;
				j = nt[j];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
