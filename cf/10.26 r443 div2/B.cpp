#include <bits/stdc++.h>
using namespace std;
const int MAX = 510;
int a[MAX];
int n;
long long k;

int main()
{
	scanf("%d%lld", &n, &k);
	int maxx = -1;
	for (int i = 0; i < n; i ++) {
		scanf("%d", &a[i]);
		maxx = max(maxx, a[i]);
	}
	if (k >= n) {
		printf("%d\n", maxx);
		return 0;
	}
	int ans = -1;
	for (int i = 0; i < n; i ++) {
		int beat;
		if (i == 0) beat = 0;
		else beat = 1;
		for (int j = (i + 1) % n; j != i; j = (j + 1) % n) {
			if (a[i] > a[j]) ++ beat;
			else break;
		}
		if (beat >= k) {
			ans = a[i];
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
} 
