#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d",&n)) {
		if (n & 1) {
			n /= 2;
		} else {
			n = n / 2 - 1;
		}
		printf("%d\n",n);
	}
	return 0;
}
