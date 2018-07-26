#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	while (scanf("%d",&n), n) {
		if ((n * n - 1) % 2 == 1) {
			printf("8600\n");
		} else {
			printf("ailyanlu\n");
		}
	}
	return 0;
}
