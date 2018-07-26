#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int n,m;
	int t;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&m);
		if (n % (m + 1) == 0 ) {
			printf("second\n");
		} else {
			printf("first\n");
		}
	}
	return 0;
} 
