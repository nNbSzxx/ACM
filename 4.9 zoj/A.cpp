#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int a,b,x,y;
		scanf("%d%d%d%d",&x,&y,&a,&b);
		int ans = 0;
		int flag = 1;
		while (a >= x || b >= y) {
			int pa = a, pb = b;
			if (a >= x) {
				ans ++;
				a = a - x + 1;
				++ b;
			}
			if (b >= y) {
				ans ++;
				b = b - y + 1;
				a ++;
			}
			if (pa <= a && pb <= b) {
				printf("INF\n");
				flag = 0;
				break;
			}
		}
		if (flag)
			printf("%d\n",ans);
	}
	return 0;
}
