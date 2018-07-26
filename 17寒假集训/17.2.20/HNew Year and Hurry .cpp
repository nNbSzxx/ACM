#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	const int all = 240;
	int n,k;
	scanf("%d%d",&n,&k);
	int time = all - k;
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		if (time - 5 * i >= 0) {
			time -= 5 * i;
			ans ++ ;
		}  else {
			break;
		}
	}
	printf("%d\n",ans);
	return 0;
}
