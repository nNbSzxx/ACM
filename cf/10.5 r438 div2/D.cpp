#include <bits/stdc++.h>
using namespace std;
const int MAX = 150;
char s[10][MAX][10];
int nt[10][MAX][10];

void getNext(char *pat, int *nt)
{
	int lenp = strlen(pat);
//	memset(nt, 0, sizeof nt);
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

bool kmp(char *tar, int n, int m)
{
	int i = 0, j = 0;
	char *pat = s[n][m];
	int *nxt = nt[n][m];
	int lent = strlen(tar);
	int lenp = strlen(pat);
	while (i < lent) {
		if (tar[i] == pat[j] || j == -1) {
			i ++; j ++;
		} else {
			j = nxt[j];
		}
		if (j == lenp) {
			return true;
		}
	}
	return false;
}

int main()
{
	memset(nt, 0, sizeof nt);
	int n;
	for (int i = 1; i <= 7; i ++) {
		for (int j = 0; j < (1 << i); j ++) {
			int temp = j, cnt = 0;
			while (cnt < i) {
				s[i][j][cnt] = (temp & 1) + '0';
				temp >>= 1;
				++ cnt; 
			}
			s[i][j][cnt] = '\0';
			getNext(s[i][j], nt[i][j]);
//			printf("%s\n", s[i][j]);
		}
	}
	scanf("%d", &n);
	char ss[300][MAX];
	for (int i = 1; i <= n; i ++) {
		scanf(" %s", ss[i]);
	}
	int q;
	scanf("%d", &q);
	for (int k = 1; k <= q; k ++) {
//		int ans = 0;
		int u, v;
		scanf("%d %d", &u, &v);
		strcpy(ss[n + k], ss[u]);
		strcat(ss[n + k], ss[v]);
		int ans = -1;
		for (int i = 1; i <= 7; i ++) {
			for (int j = 0; j < (1 << i); j ++) {
				if (!kmp(ss[n + k], i, j)) {
					ans = i - 1;
					break;
				}
			}
			if (ans != -1) break;
		}
		printf("%d\n", ans);
	}
}
