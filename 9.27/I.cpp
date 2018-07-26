#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e3 + 10;
struct item {
	long long loc, num;
} it[MAX];
int n, k;
bool cmp(const item& it1, const item& it2)
{
	return it1.loc < it2.loc;
}
int main()
{
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 1; i <= n; i ++) {
			scanf("%lld%lld", &it[i].loc, &it[i].num);
		}
		sort(it + 1, it + 1 + n, cmp);
		int l0, l1;
		for (int i = 1; i <= n; i ++) {
			if (it[i].loc >= 0) {
				l1 = i;
				break;
			}
		}
		l0 = (l1 - 1 == 0) ? -1 : l1 - 1;
//		cout << l1 << " " << l0 << endl;
		long long last = 0, ans = 0;
		for (int i = 1; i <= l0; i ++) {
			if (last >= it[i].num) {
				last -= it[i].num;
				continue;
			}
			ans += 2LL * ((it[i].num - last) / k + ((it[i].num - last) % k > 0)) * -it[i].loc;
			last = k - (it[i].num - last) % k;
			if (last == k) last = 0;
//			cout << ans << endl;
		}
//		if (last) {
//			ans += 2LL * (-it[l0].loc) * last;
//		}
//		cout << ans << endl;
		last = 0;
		for (int i = n; i >= l1; i --) {
			if (last >= it[i].num) {
				last -= it[i].num;
				continue;
			}
			ans += 2LL * ((it[i].num - last) / k + ((it[i].num - last) % k > 0)) * it[i].loc;
//			cout << i << " " << last << " " << ans << endl;
			last = k - (it[i].num - last) % k;
			if (last == k) last = 0;
		}
//		if (last) {
//			ans += 2LL * (it[l0].loc) * last;
//		}
		printf("%lld\n", ans);
	}
	
	return 0;
}
