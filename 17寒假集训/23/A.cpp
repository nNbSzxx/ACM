#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;

int main()
{
	int n;
	while (~scanf("%d",&n)) {
		int i;
		int ans = 0;
		char s[100];
		int m;
		for (i = 0; i < n; i ++) {
			scanf("%d",&m);
			itoa(m,s,16);
			//printf("%s\n",s);
			for (int j = strlen(s) - 1; j > 0; j -= 2) {
				if (s[j] == '1' && s[j - 1] == '6') {
					ans ++;
				}
			}
		}
		printf("%d\n",ans);
	}
	
	return 0;
}
