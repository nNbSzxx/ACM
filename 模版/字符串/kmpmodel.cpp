#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio> 
using namespace std;
const int MAX = 1e6 + 10;
char pat[MAX];
char tar[MAX];
int nt[MAX], ans;

void getNext()
{
	int lenp = strlen(pat);
	int lent = strlen(tar);
	memset(nt, 0, sizeof nt);
	nt[0] = -1;
	int i = 0;
	int j = -1;
	while (i < lenp) {
		if (j == -1 || pat[i] == pat[j]) {
			nt[ ++ i] = ++ j;
		} else {
			j = nt[j];
		}
	}
}

void kmp()
{
	ans = 0;
	int i = 0, j = 0;
	int lent = strlen(tar);
	int lenp = strlen(pat);
	while (i < lent) {
		if (tar[i] == pat[j] || j == -1) {
			i ++; j ++;
		} else {
			j = nt[j];
		}
		if (j == lenp) {
			ans ++;
			j = nt[j];
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf(" %s %s", pat, tar);
		getNext();
		kmp();
		printf("%d\n", ans);
	}
} 
