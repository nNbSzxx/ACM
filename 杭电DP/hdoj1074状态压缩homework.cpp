#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <stack>
using namespace std;
const int MAX = 1 << 15 + 1;

int main()
{
	char s[17][105];
	int dead[17], cost[17];
	int dp[MAX];
	int path[MAX];
	int t;
	int n;
	scanf("%d",&t);
	while ( t --) {
		scanf("%d",&n);
		memset(dp,0x3f,sizeof(dp));
		memset(path,0,sizeof(path));
		for (int i = 0; i < n; i ++) {
			scanf(" %s%d%d",s[i],&dead[i],&cost[i]);
		}
		dp[0] = 0;
		for (int st = 0; st < (1 << n); st ++) {
			int used = 0;
			for (int i = 0; i < n; i ++) {
				if (st & ( 1 << i)) {
					used += cost[i];
				}
			}
			
			for (int i = 0; i < n; i ++) {
				int cur = 1 << i;
				if ((st & cur )== 0) {
					int newt = dp[st];
					if (used + cost[i] - dead[i] > 0) {
						newt = dp[st] + cost[i] - dead[i] + used;
					}
					if (dp[st | cur] > newt) {
						dp[st | cur] = newt;
						path[st | cur] = st;
					}
				}
			}
		}
		printf("%d\n",dp[(1 << n) - 1]);
		int i = (1 << n) - 1;
		stack<char *> sta;
		while (i) {
			int p = i ^ path[i], cnt = -1;
			while (p) {
				cnt ++;
				p >>= 1;
			}
			sta.push(s[cnt]);
			i = path[i]; 
		}
		while (!sta.empty())
			printf("%s\n",sta.top()), sta.pop();
	}
	return 0;
}
