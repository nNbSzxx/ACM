#include <cstdio>
#include <algorithm>
using namespace std;

int main()
{
	int t,n;
	long long ans, num[70];
	scanf("%d",&t);
	while (t --) {
		ans = 1;
		scanf("%d",&n);
		int flag = 0;
		for (int i = 0; i < n; i ++) {
			scanf("%lld",&num[i]);
		}
		sort(num,num+n);
		for (int i = n - 1; i >= 0; i --) {
			if (num[i] >= 1) {
				flag = 1;
				ans *= num[i];
			} else {
				break;
			}
		}
		for (int i = 0; i < n - 1; i += 2) {
			if (num[i] * num[i + 1] >= 1 && num[i] < 0) {
				flag = 1;
				ans *= num[i] * num[i + 1];
			} else {
				break;
			}
		}
		if (flag) {
			printf("%lld\n",ans);
		} else {
			printf("%lld\n",num[n - 1]);
		}
	}
}
