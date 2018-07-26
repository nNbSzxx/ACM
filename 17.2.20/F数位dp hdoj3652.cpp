#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int dig[12], cnt;
int dp[12][13][3];
/*
state = 
0 ��13
1 ��13 ǰλΪ1
2 ����13
mod��ʾ��λȡ���Ľ�� �������mod == 0˵���ܱ�13���� ��λȡ��
*/
int dfs(int pos, int mod, int state, int high)
{
	if (dp[pos][mod][state] != -1 && !high) return dp[pos][mod][state];
	if (pos == 0) return (mod == 0 && state == 2);
	int bound = (high?dig[pos]:9);
	int ret = 0, m, s, h;
	for (int i = 0; i <= bound; i ++) {
		h = 0;
		s = (state == 2)?2:0;
		m = (mod * 10 + i) % 13;
		if (i == 1 && s != 2) s = 1;
		if (i == 3 && state == 1) s = 2;
		if (i == bound && high) h = 1;
		ret += dfs(pos-1, m, s, h);
	}
	if (!high) dp[pos][mod][state] = ret;
	return ret;
}
int main()
{
	int n;
	memset(dp,-1,sizeof(dp));
	while (~scanf("%d",&n)) {
		cnt = 0;
		while (n) {
			dig[++ cnt] = n % 10;
			n /= 10;
		}
		printf("%d\n",dfs(cnt, 0, 0, 1));
	}
	return 0;
}
