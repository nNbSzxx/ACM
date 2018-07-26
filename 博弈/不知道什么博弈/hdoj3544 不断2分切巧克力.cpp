#include <cstdio>
using namespace std;

int main()
{
	long long suma,sumb;
	int t,a,b,n,tc = 1;
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		suma = sumb = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d",&a,&b);
			while (a > 1 && b > 1) {
				a >>= 1;
				b >>= 1;
			}
			if (a > b) {
				suma += a;
			} else if (a < b) {
				sumb += b;
			}
		}
		printf("Case %d: ",tc ++);
		if (suma > sumb) {
			puts("Alice");
		} else {
			puts("Bob");
		}
	}
	return 0;
}
