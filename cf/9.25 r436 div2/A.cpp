#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int cnt[120];
	memset(cnt, 0, sizeof cnt);
	int t;
	int ccnt = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		++ cnt[t];
		if (cnt[t] == 1) ccnt ++;
	}
	//printf("%d\n", ccnt);
	int acnt[5], id[5];
	if (ccnt == 2) {
		int j = 1;
		for (int i = 1; i <= 100; i ++) {
			if (cnt[i]) {
				acnt[j] = cnt[i];
				id[j ++] = i;
			}
		}
		//printf("%d %d\n", acnt[1], acnt[2]);
		if (acnt[1] == acnt[2]) {
			printf("YES\n");
			printf("%d %d\n", id[1], id[2]);
		} else {
			puts("NO");
		}
	} else {
		puts("NO");
	}
	
	return 0;
}
