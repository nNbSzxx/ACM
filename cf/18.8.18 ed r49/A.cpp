#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		int n;
		char s[110];
		scanf("%d %s", &n, s + 1);
		int ok = true;
		for (int i = 1; i <= n / 2; i ++) {
			if (s[i] == s[n - i + 1] || (abs(s[i] - s[n - i + 1]) == 2)) {
				continue;
			} else {
				ok = false;
				break;
			}
		}
		if (ok) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
