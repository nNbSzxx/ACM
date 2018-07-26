#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 + 10;
int n, vis[MAX];

int main()
{
	scanf("%d", &n);
	int p;
	int last = n;
	printf("1 ");
	for (int i = 1 ;i <= n; i ++) {
		scanf("%d", &p);
		vis[p] = 1;
		while (vis[last]) -- last;
		int ans = i - (n - last) + 1;
		printf("%d ", ans);
	}
	puts("");
}
