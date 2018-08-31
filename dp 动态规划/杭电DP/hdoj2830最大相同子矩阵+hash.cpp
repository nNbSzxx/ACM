#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;
const int MAX = 1010;

int main()
{
	int n,m;
	int cnt[MAX];
	int hash[MAX];
	while (~scanf("%d%d",&n, &m)) {
		char c;
		memset(cnt,0,sizeof(cnt));
		int max = 0;
		for (int i = 1; i <= n; i ++) {
			memset(hash,0,sizeof(hash));
			for (int j = 1; j <= m; j ++) {
				scanf(" %c",&c);
				if (c == '1') {
					cnt[j] ++;
				} else {
					cnt[j] = 0;
				}
				hash[cnt[j]] ++;
			}
			
			
			for (int j = MAX - 9; j >= 1; j --) {
				hash[j] += hash[j + 1];
				if (hash[j] * j > max) {
					max = hash[j] * j;
				}
			}
		}
		printf("%d\n",max);
	}
	return 0;
}
