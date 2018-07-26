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
			if (a % 4 == 1 || a % 4 == 2) {
				ans ^= a;
			} else if (a % 4 == 3) {
				ans ^= (a + 1);
			} else {
				ans ^= (a - 1);
			}
		}
		if (ans) {
			puts("Alice");
		} else {
			puts("Bob");
		}
	}
}
