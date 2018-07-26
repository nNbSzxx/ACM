#include <cstdio>
using namespace std;

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m), n || m) {
		if (n % 2 == 0) {
			printf("Wonderful!\n");
			continue;
		}
		if ((n + m) % 2 == 0) {
			printf("What a pity!\n");
		} else {
			printf("Wonderful!\n");
		}
	}
} 
