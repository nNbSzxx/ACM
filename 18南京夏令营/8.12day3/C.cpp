#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;

int n, m;
int treesum[MAX];
int era[MAX];
char s[MAX];
set<int> loc[256];

inline int lowbit(int x)
{
	return x & (-x);
}

void modify(int x, int v)
{
	while (x <= n) {
		treesum[x] += v;
		x += lowbit(x);
	}
	return ;
}

int query(int x)
{
	int ret = x;
	while (x) {
		ret += treesum[x];
		x -= lowbit(x);
	}
	return ret;
}

int lowerb(int ll, int rr, int x)
{
	int l = ll, r = rr, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		int q = query(mid);
		if (q < x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return r + 1;
}

int upperb(int ll, int rr, int x)
{
	int l = ll, r = rr, mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		int q = query(mid);
		if (q <= x) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}
	return r;
}

int main()
{
	scanf("%d%d", &n, &m);
	scanf(" %s", s + 1);
	for (int i = 1; i <= n; i ++) {
		loc[s[i]].insert(i);
	}
	while (m --) {
		int l, r;
		char c;
		scanf("%d%d %c", &l, &r, &c);
		int rl = lowerb(1, n, l);
		int rr = upperb(rl, n, r);
		for (auto it = loc[c].begin(); it != loc[c].end(); ) {
			if (*it >= rl && *it <= rr) {
				modify(*it, -1);
				era[*it] = 1;
				loc[c].erase(it ++);
			} else if (*it > rr) {
				break;
			} else {
				++ it;
			}
		}
		//printf("%d %d\n", rl, rr);
		/*
		for (int i = rl; i <= rr; i ++) {
			if (s[i] == c && !era[i]) {
				modify(i, -1);
				era[i] = 1;
			}
		}
		*/
	}
	for (int i = 1; i <= n; i ++) {
		if (!era[i]) {
			putchar(s[i]);
		}
	}
	puts("");
	return 0;
}




