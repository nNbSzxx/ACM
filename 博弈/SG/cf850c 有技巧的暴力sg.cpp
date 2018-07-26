#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e5 + 10;
int prime[MAX], vis[MAX], cnt;
map<int, int> m, sg;

void init()
{
	for (int i = 2; i < MAX; i ++) {
		if (!vis[i]) {
			prime[cnt ++] = i;
		}
		for (int j = 0; j < cnt; j ++) {
			if (i * prime[j] >= MAX) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) break;
		}
	}
}

void split(int x)
{
	int t;
	for (int i = 0; i < cnt; i ++) {
		if (prime[i] * prime[i] > x) break;
		t = 0;
		while (x % prime[i] == 0) {
			++ t;
			x /= prime[i];
		}
		if (t)
			m[prime[i]] |= (1 << (t - 1));
	}
	if (x > 1) {
		m[x] |= 1;
	}
}

void dfs_sg(int x)
{
	if (sg.count(x)) return ;
	int v[32];
	memset(v, 0, sizeof v);
	for (int i = 1; x >> (i - 1); i ++) {
		int mask = (x >> i) | (x & ((1 << (i - 1)) - 1));
		dfs_sg(mask);
		v[sg[mask]] = 1;
	}
	for (int i = 0; ; i ++) {
		if (!v[i]) {
			sg[x] = i;
			return ;
		}
	}
}

int main()
{
	init();
	int n, a, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		split(a);
	}
	sg[0] = 0;
	
	
	for (auto it = m.begin(); it != m.end(); it ++) {
		dfs_sg(it -> second);
		ans ^= sg[it -> second];
	}
	if (ans) {
		puts("Mojtaba");
	} else {
		puts("Arpa");
	}
	return 0;
}
