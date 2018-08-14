#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 3010;
const long long INF = 3e12 + 10;
int n, m;

int get(int x)
{
	printf("? %d\n", x);
	fflush(stdout);
	int ret;
	scanf("%d", &ret);
	return ret;
}

void solve(int a1, int ah)
{
	int l = 1, r = 1 + n / 2;
	int al = a1, ar = ah;
	int mid;
	while (l < r) {
		mid = (l + r) >> 1;
		int v = get(mid);
		if (v == get(mid + n / 2)) {
			printf("! %d\n", mid);
			return ;
		}
		if (abs(v - al) > abs(v - ar)) {
			r = mid;
			ar = v;
		} else {
			l = mid;
			al = v;
		}
		if (l + 1 == r) {
			if (get(l) == get(l + n / 2)) {
				printf("! %d\n", l);
			} else if (get(r) == get(r + n / 2)) {
				printf("! %d\n", r);
			}
			return ;
		}
	}
}

int main()
{
	scanf("%d", &n);
	if (n % 4 != 0) {
		puts("! -1");
		return 0;
	}
	int a1 = get(1);
	int ah = get(1 + n / 2);
	solve(a1, ah);
	return 0;
}
