#include <bits/stdc++.h>
using namespace std;
const int MAX = 4010;
const int MAXM = 2e6 + 10;
int vis[MAXM];
int n;
int a[MAX], b[MAX];

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		vis[a[i]] = 1;
	}
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &b[i]);
		vis[b[i]] = 1;
	}
	int t;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			t = a[i] ^ b[j];
			if (t < MAXM && vis[t]) ++ ans;
		}
	}
//	cout << ans << endl;
	if (ans & 1) {
		puts("Koyomi");
	} else {
		puts("Karen");
	}
	return 0;
}
