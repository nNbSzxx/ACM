#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
int a[MAX];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		a[i] -= n - i; 
	}
	sort(a + 1, a + 1 + n);
	if (a[n] < 0) {
		puts(":(");
		return 0;
	}
	for (int i = n - 1; i >= 1; i --) {
		a[i] += n - i;
		if (a[i] > a[i + 1] || a[i] < 0) {
			puts(":(");
			return 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d ", a[i]);
	}
	return 0;
}
