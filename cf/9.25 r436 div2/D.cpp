#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
int a[MAX], vis[MAX], tag[MAX]; 
priority_queue<int, vector<int>, greater<int> > q;

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", a + i);
		vis[a[i]] ++;
	}
	for (int i = 1; i <= n; i ++) {
		if (!vis[i]) {
			q.push(i);
		}
	}
	int loc = n, cnt = 0;
	for (int i = 1; i <= n; i ++) {
		if (vis[a[i]] > 1) {
			if (a[i] > q.top() || tag[a[i]]) {
				vis[a[i]] --; ++ cnt;
				a[i] = q.top();
				q.pop();
			} else tag[a[i]] = 1;
		}
	}
	printf("%d\n", cnt);
	for (int i = 1; i <= n; i ++) {
		printf("%d ", a[i]);
	}
	puts("");
	return 0;
}
