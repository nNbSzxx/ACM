#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map> 
//using namespace std;
const int MAX = 1e6 + 10;
std::map<int, int> count;
int n;
int a[MAX];

int main()
{
	while (~scanf("%d", &n)) {
		count.clear();
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
			if (count.find(a[i]) == count.end()) {
				count.insert(std::pair<int, int>(a[i], 1));
				++ sum;
			}
		}
		count.clear();
		int cnt = 0, ans = MAX;
		int l = 1, r = 1;
		while (true) {
			if (cnt < sum) {
				if (r == n + 1) {
					break;
				}
				if (count[a[r]] == 0) {
					++ cnt;
				}
				++ count[a[r]];
				++ r;
			} else {
				-- count[a[l]];
				if (count[a[l]] == 0) {
					-- cnt;
				}
				++ l;
			}
			if (cnt >= sum) {
				ans = std::min(ans, r - l);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
