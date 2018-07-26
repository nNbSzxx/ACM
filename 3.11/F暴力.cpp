#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int dd(int x)
{
	if (x == 1) return 1;
	int ret = 1;
	int temp;
	for (int i = 2; i <= sqrt(x); i ++) {
		temp = x % i;
		if (temp == 0) {
			ret += i;
			if (i * i != x) {
				ret += x / i;
			}
		}
	}
	return ret;
}

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		if (n == 1) {
			printf("1\n");
			continue;
		}
		int ans = m;
		int d = dd(m) ;
		if (d == 1) {
			printf("%d\n",m);
			continue;
		}
		double cd = 1.0 * d / m;
		for (int i = m - 1; i >= n; i --) {
			int temp = dd(i);
			if (temp == 1) {
				ans = i;
				break;
			}
			if (1.0 * temp / i < cd) {
				cd = 1.0 * temp / i;
				ans = i;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
} 
