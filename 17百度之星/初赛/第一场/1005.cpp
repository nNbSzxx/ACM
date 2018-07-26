#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

inline bool judge(int y)
{
	return (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0));
}

int main()
{
	int t, y, m, d;
	scanf("%d", &t);
	while (t --) {
		scanf("%d-%d-%d", &y, &m, &d);
		int flag = 0;
		int run = 0;
		int step = 1;
		if (judge(y)) {
			if (m == 2 && d == 29)
				step = 4, run = 1;
		}
		if (m == 1 || m == 2) {
			m += 12;
			-- y;
			flag = 1;
		}
		int day = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7 ;
		int w;
		while (1) {
			y += step;
			if (run) {
				while (!judge(y + 1)) {
					y += step;
				}
			}
			w = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400) % 7;
			if (w == day) {
				break;
			}
		}
		if (flag) {
			++ y;
		}
		printf("%d\n", y);
	}
	return 0;
}


