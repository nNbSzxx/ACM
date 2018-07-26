#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;

int main()
{
	int n;
	while (~scanf("%d",&n)) {
		int p = sqrt(n << 1);
		while (1) {
			while ((n << 1) % p)
				p --;
			//printf("%d\n",p);
			int a = (n<<1) / p - p + 1;
			//printf("%d\n",a);
			if (a > 0 && !(a & 1)) {
				printf("%d %d\n",a >> 1,p);
				break;
			}
			p --;
		}
	}
	return 0;
}
