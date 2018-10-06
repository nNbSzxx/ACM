#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e6+5;
char s[MAX];
int nt[MAX];

int isFind (int l, int begin, int end)
{
	int i = begin;
	int j = 0;
	while (i < end) {
		if (j == -1 || s[i] == s[j]) {
			i ++;
			j ++;
		} else {
			j = nt[j];
		}
		if (j == l) {
			return 1;
		}
	}
	return 0;
}

int main()
{
	int t;
	
	scanf("%d",&t);

	while (t --) {
		scanf("%s",s);
		int len = strlen(s);
		int i = 0; int j = -1;
		nt[0] = -1;
		while (i < len) {
			if (j == -1 || s[i] == s[j]) {
				nt[++i] = ++j;
			} else {
				j = nt[j];;
			}
		}
		int l = nt[len];
		int ans = 0;
		while (l) {
			if (3 * l <= len && isFind(l, l, len - l)) {
				ans = l;
				break;
			} else {
				l = nt[l];
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
