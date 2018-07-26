#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
int n, m, a[MAX], b[MAX];

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1 ;i <= n; i ++)
		scanf("%d", &a[i]);
	for (int j = 1; j <= m; j ++)
		scanf("%d", &b[j]);
	int s1 = 0, s2 = 0, i = 1, j = 1, ans = -1;
	while (i <= n || j <= m) {
		if (s1 == s2) {
			s1 = a[i ++];
			s2 = b[j ++];
			++ ans;
		} else if (s1 < s2) {
			s1 += a[i ++];
		} else {
			s2 += b[j ++];
		}
	}
	if (s1 == s2) ++ ans;
	printf("%d\n", ans);
}
