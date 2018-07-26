#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6 + 10;
int lt, lp, nt[MAX], treesum[MAX];
char pat[MAX], tag[MAX];

inline int lowbit(int x)
{
	return x & (-x);
}

void update(int x, int v)
{
	while (x) {
		treesum[x] += v;
		x -= lowbit(x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x <= lp) {
		ret += treesum[x];
		x += lowbit(x);
	}
	return ret;
}

void inverse(char *s, int len)
{
	for (int i = 0; i < len / 2; i ++) {
		s[i] ^= s[len - i - 1];
		s[len - i - 1] ^= s[i];
		s[i] ^= s[len - i - 1];
	}
}

void getnt(void)
{
	nt[0] = -1;
	int i = 0, j = -1;
	while (i < lp) {
		if (j == -1 || pat[i] == pat[j]) {
			nt[++ i] = ++ j;
		} else {
			j = nt[j];
		}
	}
}

void kmp(void)
{
	int i = 0, j = 0;
	while (i < lt) {
		if (j == -1 || tag[i] == pat[j]) {
			++ i, ++ j;
		} else {
			update(j, 1);
			j = nt[j];
		}
	}
	while (j != -1) {
		update(j, 1);
		j = nt[j];
	}
}
int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		memset(treesum, 0, sizeof treesum);
		scanf(" %s %s", tag, pat);
		lt = strlen(tag);
		lp = strlen(pat);
		inverse(tag, lt);
		inverse(pat, lp);
		getnt();
		kmp();
		long long ans = 0;
		for (int i = 0; i < lp; i ++) {
			ans = (ans + 1LL * query(i + 1) * (i + 1)) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

