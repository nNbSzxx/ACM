#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 1e3 + 10;
int p[MAX];
int n;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &p[i]);
	}
	int vis[MAX];
	for (int i = 1; i <= n; i ++) {
		memset(vis, 0, sizeof vis);
		vis[i] = 1;
		int cur = i;
		while (true) {
			cur = p[cur];
			++ vis[cur];
			if (vis[cur] == 2) {
				break;
			}
		}
		printf("%d ", cur);
	}
	return 0;
}
