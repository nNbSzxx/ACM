#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 5e4 + 10;
long long n;
struct cow {
	long long w, s;
} c[MAX];

bool cmp(const cow& c1, const cow& c2)
{
	return (c1.s + c1.w < c2.s + c2.w);
}

int main()
{
	while (~scanf("%d", &n)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lld%lld", &c[i].w, &c[i].s);
		}
		sort(c + 1, c + 1 + n, cmp);
		long long maxx = 0x8000000000000000L, sum = 0;
		for (int i = 1; i <= n; i ++) {
			long long risk = sum - c[i].s;
			maxx = max(risk, maxx);
			sum += c[i].w; 
		}
		printf("%lld\n", maxx);
	}
	return 0;
}
