#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int n,a,ans = 0;
		scanf("%d",&n);
		for (int i= 1; i <= n; i ++) {
			scanf("%d",&a);
			if (a % 8 == 0 ) {
				ans ^= a - 1;
			} else if (a % 8 == 7) {
				ans ^= a + 1;
			} else {
				ans ^= a;
			}
		}
		if (ans) {
			puts("First player wins.");
		} else {
			puts("Second player wins.");
		}
	}
}
