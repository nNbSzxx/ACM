#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e5 + 10;
const int INF = 1e6;
vector<int> a;
int n;

int check(int i1, int j1)
{
//	printf("check: %d %d\n", i1, j1);
	int ret = abs(i1) + abs(j1);
	vector<int> tmp = a;
	tmp[0] += i1;
	tmp[1] += j1;
	int d = tmp[1] - tmp[0];
//	printf("d: %d\n", d);
	for (int i = 1; i < n; i ++) {
		int del = tmp[i] - tmp[i - 1];
//		printf("i, del: %d %d\n", i, del);
		if (del + 1 == d) {
			tmp[i] += 1;
			ret += 1;
		} else if (del - 1 == d) {
			tmp[i] -= 1;
			ret += 1;
		} else if (del == d) {
			continue;
		} else {
			return INF;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int t;
		scanf("%d", &t);
		a.push_back(t);
	}
	if (n <= 2) {
		puts("0");
		return 0;
	}
	int ans = INF;
	for (int i = -1; i <= 1; i ++) {
		for (int j = -1; j <= 1; j ++) {
			ans = min(ans, check(i, j));
		}
	}
	if (ans != INF)
		printf("%d\n", ans);
	else 
		puts("-1");
	return 0;
}
