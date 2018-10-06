#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 50010;

int main()
{
	int nt[MAX], ans[MAX];
	char s1[MAX],s2[MAX];
	while (~scanf(" %s %s",s1,s2)) {
		int len1 = strlen(s1);
		int i = 0;
		int j = -1;
		nt[0] = -1;
		while (i < len1) {
			if (j == -1 || s1[i] == s1[j]) {
				nt[++i ] = ++j;
			} else {
				j = nt[j];
			}
		}
		int len2 = strlen(s2);
		i = 0;
		j = 0;
		while (i < len2) {
			if (j == -1 || s2[i] == s1[j]) {
				ans[++i] = ++j;
			} else {
				j = nt[j];
			}
		}
		for (int i = 0; i < ans[len2]; i ++) {
			printf("%c",s1[i]);
		}
		printf(ans[len2]>0?" %d\n":"%d\n",ans[len2]);
	}
}
