#include <iostream>
#include <cstdio>
using namespace std;

const int MAX = 1010;
int c[MAX];

int main()
{
	int n,i,j;

	while (~scanf("%d",&n)) {
		int i;
		double ret = 0;
		if (n == 1) {	
			int temp;
			scanf("%d",&temp);
			printf("%d\n",temp);
			continue;
		}
		for (i = 1; i <= n; i ++) {
			scanf("%d",&c[i]);
			if ( i == 1 || i == n)
			ret += 0.5 * c[i];
			else 
			ret += 1.0 / 3 * c[i];
		}
		printf("%.6f\n", ret);
	}
	return 0;
}
