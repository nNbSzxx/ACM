#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 35;

struct Box {
	int a,b,h;
};
bool cmp(Box &a, Box &b)
{
	if (a.a > b.a) {
		return true;
	} else {
		if (a.a == b.a && a.b > b.b) {
			return true;
		}
	}
	return false;
}
int bigger(int a, int b) {
	return (a > b) ? a : b;
}
int smaller(int a, int b) {
	return (a < b) ? a : b;
}
int main()
{
	int n;
	Box box[MAX * 3];
	int dp[MAX * 3];
	int t = 1;
	while (scanf("%d", &n), n) {
		for (int i = 1; i <= 3 * n; i += 3) {
			int a,b,c;
			scanf("%d%d%d",&a,&b,&c);
			box[i].h = a;
			box[i].a = bigger(b,c);
			box[i].b = smaller(b,c);
			box[i + 1].h = b;
			box[i + 1].a = bigger(a,c);
			box[i + 1].b = smaller(a,c);
			box[i + 2].h = c;
			box[i + 2].a = bigger(b,a);
			box[i + 2].b = smaller(b,a);
		}
		memset(dp,0,sizeof(dp));
		sort(box+1, box+n*3+1,cmp);
		dp[1] = box[1].h;
		for (int i = 2; i <= 3 * n; i ++) {
			dp[i] = box[i].h;
			for (int j = 1; j < i; j ++) {
				if (dp[i] < dp[j] + box[i].h && box[i].a < box[j].a && box[i].b < box[j].b) {
					dp[i] = dp[j] + box[i].h;
				}
			}
		}
		int max = 0;
		for (int i = 1; i <= 3 * n ; i++) {
			if (max < dp[i]) {
				max = dp[i];
			}
		}
		printf("Case %d: maximum height = %d\n",t ++, max);
	} 
	return 0;
}
