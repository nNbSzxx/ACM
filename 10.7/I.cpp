#include <bits/stdc++.h>
using namespace std;
const int MAX = 1010;
int n, m;

inline bool valid(int x, int y)
{
	return x >= 0 && y >= 0 && x <= m && y <= m;
}

int main()
{
	while (~scanf("%d%d", &m, &n)) {
		int x = 0, y = 0;
		int d = 0;
		char s[20]; int id, flag = 1;
		for (int i = 1; i <= n; i ++) {
			scanf(" %s %d", s, &id);
			if (!strcmp(s, "TURN")) {
				if (id == 0) {
					d = (d + 1) % 4;
				} else {
					d = (d - 1 + 4) % 4;
				}
			} else {
				switch(d) {
					case 0:
						x += id;
						break;
					case 1:
						y += id;
						break;
					case 2:
						x -= id;
						break;
					case 3:
						y -= id;
						break;
				}
				if (!valid(x, y)) {
					flag = 0;
				}
			}
//			cout << d << " " << x << " " << y << endl;
		}
		if (flag) {
			printf("%d %d\n", x, y);
		} else {
			puts("-1");
		}
	}
}
