#include <cstdio>
using namespace std;

int main()
{
	int n,m,t;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		if (n % (m + 1) == 0) {
			puts("Rabbit");
		} else {
			puts("Grass");
		}
	}
	return 0;
}
