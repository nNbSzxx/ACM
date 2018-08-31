#include <iostream>
#include <cstdio>
#include <cstring>
//#include <algorithm>
using namespace std;
const int MAX = 200005;

inline int Max(int a, int b)
{
	return a>b?a:b;
}
int main()
{
	int dpi[MAX],dpj[MAX];
	int n,m;
	int temp;
	while (~scanf("%d%d",&n,&m) ) {
		memset(dpi,0,sizeof(dpi));
		for (int i = 1; i <= n; i ++) {
			
			for (int j = 1; j <= m; j ++) {
				scanf("%d",&temp);
				if (j != 1)
					dpi[j] = Max(dpi[j - 2] + temp, dpi[j - 1]);
				else 
					dpi[j] = temp;
			}
			dpj[i] = dpi[m];
		}
		memset(dpi,0,sizeof(dpi));
		dpi[1] = dpj[1];
		for (int i = 2; i <= n; i ++) {
			dpi[i] = Max(dpi[i - 2] + dpj[i], dpi[i - 1]);
		}
		printf("%d\n",dpi[n]);
	}
	return 0;
}
