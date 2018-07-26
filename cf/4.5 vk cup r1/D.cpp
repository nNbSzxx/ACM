#include <stdio.h>
// ??? why can't I submit my code ???
int main()
{
	int n,l,r,a[100010];
	while (~scanf("%d%d%d",&n,&l,&r)) {
		int flag = 1;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
		}
		int t;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&t);
			if ((i < l || i > r) && t != a[i]) {
				flag=0;
			}
 		}
 		if (flag) printf("TRUTH\n");
 		else printf("LIE\n");
	}
}
