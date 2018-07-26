#include <cstdio>
using namespace std;

int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int t;
	int a,b,c;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d%d",&a,&b,&c);
		if ((a < c && b < c) || c % gcd(a,b)) {
			printf("-1\n");
			continue;
		}
		int aa = 0, bb = 0, cnt = 0;
		while (aa != c && bb != c) {
			if (aa == 0) {
				aa = a;
				cnt ++;
				continue;
			}
			if (bb == b) {
				bb = 0;
				cnt ++;
				continue;
			}
			bb += aa;
			aa = 0;
			if (bb > b) {
				
				aa = bb - b;
				bb = b;
			}
			cnt ++;
		}
		int ans = cnt;
		aa = 0; bb = 0; cnt = 0;
		while (aa != c && bb != c) {
			if (bb == 0) {
				bb = b;
				cnt ++;
				continue;
			}
			if (aa == a) {
				aa = 0;
				cnt ++;
				continue;
			}
			aa += bb;
			bb = 0;
			if (aa > a) {
				
				bb = aa - a;
				aa = a;
			}
			cnt ++;
		}
		if (cnt < ans) ans = cnt;
		printf("%d\n",ans);
	}
}
