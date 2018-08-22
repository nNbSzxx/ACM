#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 2e5 + 10;
vector<int> ans[MAX];
int cnt = 0;
int n;

int bins(int x)
{
	int l = 1, r = cnt;
	int mid, ret = cnt + 1;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (ans[mid].back() < x) {
			ret = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}
	return ret;
}

int main()
{
	scanf("%d", &n);
	int a;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a);
		int id = bins(a);
		if (id > cnt) {
			++ cnt;
		}
		ans[id].push_back(a);
	}
	for (int i = 1; i <= cnt; i ++) {
		for (int a : ans[i]) {
			printf("%d ", a);
		}
		puts("");
	}
	return 0;
}
