#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int n; 
		scanf("%d",&n);
		int flag = 0, m, ans = 0;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&m);
			if (m > 1) {
				flag = 1;
			}
			ans ^= m;
		}
		if (flag) {
			if (ans) {
				printf("John\n");
			} else {
				printf("Brother\n");
			}
		} else {
			if (ans) {
				printf("Brother\n");
			} else {
				printf("John\n");
			}
		}
	}
	return 0;
}
