#include <cstdio>
#include <set>
using namespace std;

int main()
{
	int n;
	set<int> s;
	while (~scanf("%d",&n)) {
		if (n == 0) {
			printf("Yes\n");
			continue;
		}
		s.clear();
		int t, cnt = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&t);
			if (!s.count(t))
				s.insert(t), cnt ++ ;
		}
		if (cnt % 2 == 1) {
			printf("No\n");
			continue;
		}
		int ans = 0;
		for (auto it = s.begin(); it != s.end(); it ++) {
			ans ^= *it;
		}
		if (ans) {
			printf("No\n");
		} else {
			printf("Yes\n");
		}
	}
	return 0;
}
