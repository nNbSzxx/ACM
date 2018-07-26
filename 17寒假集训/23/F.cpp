#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	char s[100005];
	int vis[256];
	while (~scanf("%d",&n)) {
		memset(vis,0,sizeof(vis));
		int want = 0;
		for (int i = 1; i <= n; i ++) {
			scanf(" %c",&s[i]);
			if (!vis[s[i]]) {
				want ++;
				vis[s[i] ] = 1;
			}
		}
	
		memset(vis,0,sizeof(vis));
		int left = 1;
		int right = 1;
		int cur = 1;
		vis[s[1]] = 1;
		int ans = 0x3f3f3f3f;
		if (cur == want) ans = 1;
		
		while (right < n) {
			right ++;
			if (!vis[s[right]]) cur ++;
			vis[s[right]] ++;
			while (vis[s[left]] > 1) {
					
				vis[s[left]] --;
				left ++;
			}
			
			if (cur == want && right - left + 1 < ans)
				ans = right - left + 1;
			
		}
		printf("%d\n",ans);
	}
	return 0;
}

