#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
int n, m;
unsigned int A, B, C, x, y, z;
const int MAX = 1e7 + 10;
unsigned int a[MAX], ans[110];
struct req {
	int k, id;
} r[110];

unsigned rng61() {
  	unsigned t;
  	x ^= x << 16;
  	x ^= x >> 5;
  	x ^= x << 1;
  	t = x;
  	x = y;
  	y = z;
  	z = t ^ x ^ y;
  	return z;
}
bool cmp(const req& r1, const req& r2)
{
	return r1.k > r2.k;
}

int main()
{
	int t = 1;
	while (~scanf("%d", &n)) {
		scanf("%d%u%u%u", &m, &A, &B, &C);
		x = A; y = B; z = C;
		for (int i = 0; i < m; i ++) {
			scanf("%d", &r[i].k);
			r[i].id = i;
		}
		for (int i = 0; i < n; i ++) {
			a[i] = rng61();
		}
		sort(r, r + m, cmp);
		int range = n;
		for (int i = 0; i < m; i ++) {
			nth_element(a, a + r[i].k, a + range);
			ans[r[i].id] = a[r[i].k];
			range = r[i].k;
		}
		printf("Case #%d: %u", t ++, ans[0]);
		for (int i = 1; i < m; i ++) {
			printf(" %u", ans[i]);
		}
		puts("");
	}
	return 0; 
}
