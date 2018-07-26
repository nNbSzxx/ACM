#include <cstdio>
#include <algorithm>
using namespace std;

struct S{
	int h;
	int c;
} s[510];

bool cmp (S& s1, S& s2)
{
	return ((long long)s1.h * s1.h - s1.h * s1.c - s1.c * s1.c > (long long)s2.h * s2.h - s2.h * s2.c - s2.c * s2.c);
}
int main()
{
	int t;
	long long sh;
	long long satis;
	int sc, h, c, n;
	scanf("%d",&t);
	while (t --) {
		scanf("%d",&n);
		sc = 0;
		sh = 0;
		satis = 0;
		for (int i = 0; i < n; i ++) {
			scanf("%d%d",&s[i].h,&s[i].c);
		}
		sort (s, s + n, cmp);
		for (int i = 0; i < n; i ++) {
			if ((long long)s[i].h*(2*sh+s[i].h-sc)-s[i].c*(2*sc+s[i].c+sh+s[i].h) > 0) {
				sh += s[i].h;
				sc += s[i].c;
			}
		}
		satis = sh * sh - sh * sc - sc * sc;
		printf("%lld\n",satis);
	}
	return 0;
}
