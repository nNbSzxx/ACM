#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 1010;

int main()
{
	int len1, len2;
	int nt[MAX];
	char s1[MAX], s2[MAX];
	while (scanf(" %s",s1), strcmp(s1,"#")) {
		int i = 0;
		int j = -1;
		scanf(" %s",s2);
		len1 = strlen(s1);
		len2 = strlen(s2);
		nt[0] = -1;
		while (i < len2) {
			if (j == -1 || s2[i] == s2[j]) {
				nt[++ i] = ++ j;
			} else {
				j = nt[j];
			}
		}
		i = 0; j = 0;
		int ans = 0;
		while (i < len1) {
			if (j == -1 || s1[i] == s2[j]) {
				i ++;
				j ++;
			} else {
				j = nt[j];
			}
			if (j == len2) {
				ans ++;
				j = 0;
			}
		}
		printf("%d\n",ans);
	}
} 
