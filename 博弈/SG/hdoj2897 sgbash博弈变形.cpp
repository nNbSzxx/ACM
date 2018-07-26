#include <cstdio>
using namespace std;

int main()
{
	int n,p,q;
	while (~scanf("%d%d%d",&n,&p,&q)) {
		n %= p + q ;
		if (n <= p && n != 0) {
			puts("LOST");
		} else {
			puts("WIN");
		}
	}
	return 0;
}
