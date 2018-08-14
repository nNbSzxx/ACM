#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int n;
char s[110];

int main()
{
	scanf("%d", &n);
	scanf(" %s", s);
	int cnt = 0;
	int ans = 0;
	for (int i = 0; i < n; i ++) {
		if (s[i] == 'x') {
			++ cnt;
		} else {
			ans += max(0, cnt - 2);
			cnt = 0;
		}
	}
	ans += max(0, cnt - 2);
	printf("%d\n", ans);
	return 0;
}
