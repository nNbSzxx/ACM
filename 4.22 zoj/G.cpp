#include <cstdio>
using namespace std;

int main()
{
	int n,t;
	int a[100005], b[100005];
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
		}
		int flag = 0, loc1 = 0, loc2 = 0, cnt1 = 0, cnt2 = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&b[i]);
			if (b[i] == 1 && a[i] > 1) {
				cnt1 ++;
				loc1 = i;
			}
			if (b[i] == 2) {
				cnt2 ++;
				loc2 = i;
				if (a[i] % 2 == 1) {
					flag = 1;
				}
			}
		}
		if (cnt2 >= 2 || flag || cnt1 >= 2 || cnt1 + cnt2 >= 2) {
			printf("Bob\n");
			continue;
		}
		int x = 0;
		for (int i = 1; i <= n; i ++) {
			x ^= a[i];
		}
		if (cnt1 == 1) {
			if (a[loc1] % 2 == 1) {
				x ^= a[loc1];
				if (x > 0) {
					printf("Bob\n");
				} else {
					printf("Alice\n");
				}
				continue;
			} else {
				x ^= a[loc1] ^ 1;
				if (x > 0) {
					printf("Bob\n");
				} else {
					printf("Alice\n");
				}
			}
			continue;
			
		}
		if (cnt2 == 1) {
			x ^= a[loc2];
			if (x > 0) {
				printf("Bob\n");
			} else {
				printf("Alice\n");
			}
			continue;
		}
		if (x > 0) {
			printf("Alice\n");
		} else {
			printf("Bob\n");
		}
	}
}
