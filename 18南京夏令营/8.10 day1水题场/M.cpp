#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
using namespace std;
const int MAX = 110;
int occ[MAX];

struct task {
	int be;
	int de;
	int ne;
	int id;
} t[MAX];

bool cmp(const task& t1, const task& t2)
{
	return t1.de < t2.de;
}

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d%d", &t[i].be, &t[i].de, &t[i].ne);
		t[i].id = i;
		occ[t[i].de] = m + 1;
	}
	sort(t + 1, t + 1 + m, cmp);
	for (int i = 2; i <= m; i ++) {
		if (t[i].de == t[i - 1].de) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= m; i ++) {
		int cnt = 0;
		for (int j = t[i].be; j < t[i].de; j ++) {
			if (!occ[j]) {
				occ[j] = t[i].id;
				++ cnt;
				if (cnt >= t[i].ne) {
					break;
				}
			}
		}
		if (cnt < t[i].ne) {
			puts("-1");
			return 0;
		}
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d ", occ[i]);
	}
	return 0;
}

