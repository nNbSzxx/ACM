#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int m,x1,x2,y1,y2;
		scanf("%d%d%d%d%d",&m,&x1,&y1,&x2,&y2);
		int dis = abs(x1-x2) + abs(y1-y2);
//		if (dis == 1 && m == 1) {
//			printf("2\n");
//			continue;
//		}
		if (dis % 2 == 0) {
			if (m <= 2 * (dis-1)) {
				if (m & 1) {
					printf("1\n");
				} else {
					printf("-1\n");
				}
			} else {
				if (m & 1) {
					printf("-1\n");
				} else {
					printf("1\n");
				}
			}
		} 
		if (dis & 1) {
			if (m <= 2*(dis-1)) {
				if (m & 1) {
					printf("1\n");
				} else {
					printf("-1\n");
				}
			} 
			if (m > 2*(dis-1) && m < 2 * dis) {
				if (m & 1) {
					printf("2\n");
				} else {
					printf("0\n");
				}
			}
			if (m >= 2 * dis) {
				if (m & 1) {
					printf("1\n");
				} else {
					printf("-1\n");
				}
			}
		}
	}
	return 0;
}



