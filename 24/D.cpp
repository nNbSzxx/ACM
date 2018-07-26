#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char s[20][66];
const int mod = 1e9 + 7;
int trans(char* x, char* y)
{
	int cur,dis;
	cur = dis = dist(x,y);
	int ans = 0;
	for(int i= 0; i < n; i ++) {
		if (xor(x,y) < )
	}
}

int main()
{
	int t;
	scanf("%d",&t);
	int n,m;

	while (t --) {
		for (int i = 0; i < n; i ++) {
			int temp
			scanf("%d",&temp) ;
			itoa(temp,s[i],2);
			for (int j = strlen(s[i]); j <= 64; j ++) {
				s[j] = '0';
			}
		}
		for (int i = 0; i < m; i ++) {
			int x,y;
			char s1[66],s2[66];
			scanf("%d%d",&x,&y);
			itoa(x,s1,2);
			itoa(y,s2,2);
			for (int j = strlen(s1); j <= 64; j ++)
				s1[j] = '0';
			for (int j = strlen(s2); j <= 64; j ++)
				s2[j] = '0';
			int ans = (ans + trans(s1,s2) % mod) % mod;
		}
	}
}
