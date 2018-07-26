#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int n;
int s, d;

int main()
{
	int ans = 0; 
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d%d", &s, &d);
		if (ans >= s) {
			ans = (s + (d + ans - s) / d * d);
		} else {
			ans = s;
		}
	}
	printf("%d\n", ans);
}
