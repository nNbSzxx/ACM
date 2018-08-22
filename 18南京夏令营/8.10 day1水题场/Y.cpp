#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
vector<int> gou[2], gu[2];
int a, b;

void check(int x, int id)
{
	for (int i = 4; i < x; i ++) {
		for (int j = 3; j <= i; j ++) {
			if (i * i + j * j == x * x) {
				gou[id].push_back(j);
				gu[id].push_back(i);
			}
		}
	}
}

bool judge(int x1, int y1, int x2, int y2)
{
	if (!((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) == a * a + b * b)) {
		return false;
	}
	if (y1 == y2) {
		return false;
	}
	return true;
}

int main()
{
	scanf("%d%d", &a, &b);
	check(a, 0);
	check(b, 1);
	bool ok = false;
	for (int i = 0; i < gou[0].size(); i ++) {
		int gou1 = gou[0][i];
		int gu1 = gu[0][i];
		for (int j = 0; j < gou[1].size(); j ++) {
			int gou2 = gou[1][j];
			int gu2 = gu[1][j];
			if (judge(-gou1, gu1, gou2, gu2)) {
				puts("YES");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", -gou1, gu1);
				printf("%d %d\n", gou2, gu2);
				return 0;
			}
			if (judge(-gu1, gou1, gu2, gou2)) {
				puts("YES");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", -gu1, gou1);
				printf("%d %d\n", gu2, gou2);
				return 0;
			}
			if (judge(-gou1, gu1, gu2, gou2)) {
				puts("YES");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", -gou1, gu1);
				printf("%d %d\n", gu2, gou2);
				return 0; 
			}
			if (judge(-gu1, gou1, gou2, gu2)) {
				puts("YES");
				printf("%d %d\n", 0, 0);
				printf("%d %d\n", -gu1, gou1);
				printf("%d %d\n", gou2, gu2);
				return 0; 
			}
		}
	}
	puts("NO");
	return 0;
} 
