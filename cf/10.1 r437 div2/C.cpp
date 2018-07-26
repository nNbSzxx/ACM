#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
struct item {
	long long num, a, b;
	long long del;
} it[MAX];
int n, s;
long long summ, sumb;

bool cmp(const item& it1, const item& it2)
{
	return it1.del > it2.del;
}

int main()
{
	scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld%lld%lld", &it[i].num, &it[i].a, &it[i].b);
		it[i].del = (it[i].a - it[i].b);
		summ += it[i].num;
		sumb += it[i].b * it[i].num;
	}
	long long p = summ / s + (summ % s > 0);
	long long left = p * s - summ;
	sort(it + 1, it + 1 + n, cmp);
	int loc2 = 0;
	long long sum[3] = {0}, sump[3] = {0};
	
	for (int i = 1; i <= n; i ++) {
		if (it[i].del <= 0) {
			loc2 = i - 1;
			break;
		}
		sump[2] += it[i].num;
		sum[2] += it[i].del * it[i].num;
	}
	
	int i = loc2 + 1;
	while (it[i].del == 0) i ++;	
	int loc1 = i;
	for (int i = loc2 + 1; i < loc1; i ++) {
		sump[0] += it[i].num;
	}
	
	long long ans = sumb, t;
	sumb += sum[2];
	t = sumb;
	long long na = sump[2] / s + (sump[2] % s > 0);
	long long duo = na * s - sump[2];
	duo -= left;
	duo -= sump[0];
	i = loc1;
	while (duo > 0) {
		if (duo >= it[i].num) {
			sumb += it[i].del * it[i].num;
			duo -= it[i].num;
		} else {
			sumb += it[i].del * duo;
			duo = 0;
		}
		++ i;
	}
	ans = max(ans, sumb);
	sumb = t;
	
	long long nb = na - 1;
	long long shao = sump[2] - nb * s;
//	shao -= left;
//	shao -= sump[0];
	i = loc2;
	while (shao > 0) {
		if (shao >= it[i].num) {
			sumb -= it[i].del * it[i].num;
			shao -= it[i].num;
		} else {
			sumb -= it[i].del * shao;
			shao = 0;
		}
		-- i;
	}
	ans = max(ans, sumb);
	printf("%lld\n", ans);
	return 0;
}
