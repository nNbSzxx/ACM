#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
struct node {
	int n, id, islucky;
} pre[MAX], post[MAX];
int n, ansx[2 * MAX], ansy[2 * MAX], cnt;
int pos[MAX], rpos[MAX];

void change(int x, int y)
{
//	cout << x << " " << y << endl;
	if (x == y) return;
	ansx[cnt] = x;
	ansy[cnt ++] = y;
	swap(rpos[pos[x]], rpos[pos[y]]);
	swap(pos[x], pos[y]);
	return ;
}
void changeval(int x, int y)
{
//	cout << rpos[x] << " " << rpos[y] << endl;
	change(rpos[x],rpos[y]);
}
bool cmp1(const node& n1, const node& n2)
{
	return n1.n < n2.n;
}
inline int islucky(int x)
{
	int digit;
	while (x) {
		digit = x % 10;
		if (digit != 4 && digit != 7) {
			return 0;
		}
		x /= 10;
	}
	return 1;
}

int main()
{
	scanf("%d", &n);
	int loc = 0, flag = 1;
	pre[0].n = -1;
	pre[0].id = 0;
	pre[0].islucky = 0;
	for (int i = 1; i <= n; i ++) {
		pos[i] = rpos[i] = i;
		scanf("%d", &pre[i].n);
		post[i].n = pre[i].n;
		if (pre[i].n < pre[i - 1].n) {
			flag = 0;
		}
		pre[i].id = post[i].id = i;
		pre[i].islucky = post[i].islucky = islucky(pre[i].n);
	}
	sort (post + 1, post + 1 + n, cmp1);
//	for (int i = 1; i <= n; i ++) {
//		post[i].id = i;
//	}
	for (int i = 1; i <= n; i ++) {
		if (pre[i].islucky) {
			loc = i;
			break;
		}
	}
	if (loc == 0) {
		if (flag) {
			puts("0");
		} else {
			puts("-1");
		}
		return 0;
	}
	if (flag) {
		puts("0");
		return 0;
	}
	cnt = 1;
	for (int i = 1; i <= n; i ++) {
		int to = post[i].id;
		if (to == loc) {
			continue;
		}
//		cout << pos[i] << " " << loc << " " << to << endl;
		changeval(pos[i], loc);
		changeval(loc, to);
	}
	printf("%d\n", cnt - 1);
	for (int i = 1; i <= cnt - 1; i ++) {
		printf("%d %d\n", ansx[i], ansy[i]);
	}
	return 0;
}

