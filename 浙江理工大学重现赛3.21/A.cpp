#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int t;
	char s[50010];
	scanf("%d",&t);
	while (t --) {
		scanf(" %s",s);
		int len = strlen(s);
		if (len <= 2) {
			printf("NO\n");
			continue;
		}
		if (s[0] == s[len - 1]) {
			printf("YES\n");
			continue;
		}
		printf("NO\n");
	}
}
