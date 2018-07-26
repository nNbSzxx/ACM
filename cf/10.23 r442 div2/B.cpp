#include <bits/stdc++.h>
using namespace std;
const int MAX = 5050;
char s[MAX];
int cnta[MAX], cntb[MAX];

int main()
{
	scanf(" %s", s + 1);
	int len = strlen(s + 1);
	for (int i = 1; i <= len; i ++) {
		cnta[i] = cnta[i - 1] + (s[i] == 'a');
		cntb[i] = cntb[i - 1] + (s[i] == 'b');
	}
	int ans = 0;
	for (int i = 0; i <= len; i ++) {
		for (int j = i; j <= len; j ++) {
			ans = max(ans, cnta[i] + (cntb[j] - cntb[i]) + (cnta[len] - cnta[j]));
		}
	}
	printf("%d\n", ans);
	return 0;
}
