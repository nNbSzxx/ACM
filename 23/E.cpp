#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int b, ls;
		scanf("%d%d",&b,&ls);
		double max = sqrt(b*b+ls*ls);
		double min = sqrt(ls*ls-b*b);
		printf("%.4f %.4f\n",min, max);
	}
}
