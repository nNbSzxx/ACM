#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100005;
int main()
{
	int n;
	int num[MAX * 2];
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; i ++) {
			int w,l;
			scanf("%d%d",&w,&l);
			num[i] = num[i + n] = w - l;
		}
		int max = 0, sum = 0, cnt = 0;
		for (int i = 1; i <= 2 * n; i ++) {
			sum += num[i];
			if (sum >= 0) {
				cnt ++;
				if (cnt > max) {
					max = cnt;
					if (max == n) {
						break;
					}
				}
			} else {
				sum = cnt = 0;
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
