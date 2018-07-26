#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int main()
{
	int a,b;
	while (~scanf("%d%d",&a,&b)) {
		if (a > b) {
			swap(a,b);
		}
		int t = (b - a) * (sqrt(5) + 1) / 2.0;
		if (t == a) {
			puts("0");
		} else {
			puts("1");
		}
	}
	return 0;
}
