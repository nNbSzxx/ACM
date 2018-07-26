#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int n,t;
	while (~scanf("%d",&n)) {
		int ans = 0, flag = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&t);
			if (t > 1) {
				flag = 1;
			}
			ans ^= t;
		}
		if (flag) {
			if (ans) {
				printf("Yes\n");
			} else {
				printf("No\n");
			}
		} else {
			if (ans)
				printf("No\n");
			else 
				printf("Yes\n");
		}
	}	
} 
