#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	int n,m;
	while (t --) {
		scanf("%d%d",&n,&m);
		int temp;
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				scanf("%d",&temp);
			}
		}
		if (temp == 1) {
			puts("Alice");
		} else {
			puts("Bob");
		}
		
	}
	return 0;
}
