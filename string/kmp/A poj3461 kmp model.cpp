#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;

const int MAX = 1e4 + 10;

int main()
{
	int tc;
	scanf("%d",&tc) ;
	char w[10010], t[1000010];
	int next[MAX];
	while (tc --) {
		int ans = 0;
		memset(next, 0, sizeof(next));
		scanf(" %s %s",w,t);
		int lenw = strlen(w);
		int lent = strlen(t);
		next[0] = -1;
		int i = 0;
		int j = -1;
		while (i < lenw) {
			if (j == -1 || w[i] == w[j]) {
				next[ ++ i] = ++ j;
			} else {
				j = next[j];
			}
		}
		i = 0;j = 0;
		while (i < lent) {
			if (t[i] == w[j] || j == -1) {
				i ++; j ++;
			} else {
				j = next[j];
			}
			if (j == lenw) {
				ans ++;
				j = next[j];
			}
		} 
		printf("%d\n",ans);
	}
}
