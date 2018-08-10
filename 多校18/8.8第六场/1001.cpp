#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
const double PI = acos(-1.0);
int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		int a, b;
		scanf("%d%d", &a, &b);
		double ans = PI * a + 2.0 * b;
		printf("%.6f\n", ans - 0.0000005);
	}
	return 0;
}
