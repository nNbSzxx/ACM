#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 105;
struct Node{
	int b,e;
};
bool cmp(Node &p1, Node &p2)
{
	return p1.b < p2.b;
}
int main()
{
	int n;
	Node p[MAX];
	int dp[MAX];
	int nt[MAX];
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= n; i ++) {
			dp[i] = 1;
			scanf("%d%d",&p[i].b, &p[i].e);
			if (p[i].b > p[i].e) {
				p[i].b ^= p[i].e;
				p[i].e ^= p[i].b;
				p[i].b ^= p[i].e;
			}
		}
		sort(p+1,p+1+n,cmp);
		int m = 1, maxid = 1;
		for (int i = n - 1; i >= 1; i --) {
			for (int j = i + 1; j <= n; j ++) {
				if (p[i].e <= p[j].b) {
					if (dp[i] < dp[j] + 1) {
						dp[i] = dp[j] + 1;
						nt[i] = j;
					}					
				}
			}
			if (dp[i] > m) {
				m = dp[i];
				maxid = i;
			}
		}
//		for (int i = 1; i <= n; i ++) {
//			printf("%d %d\n",p[i].b,p[i].e);
//		}
//		for (int i = 1; i<= n; i ++) {
//			printf("%d ",dp[i]);
//		}
//		printf("\n");
//		for (int i = 1; i <= n; i ++) {
//			printf("%d ",nt[i]);
//		}
//		printf("\n");
		printf("%d\n",m);
		int i = maxid;
		while (m --) {
			printf("%d %d\n",p[i].b,p[i].e);
			i = nt[i];
		}
	}
	return 0;
}
