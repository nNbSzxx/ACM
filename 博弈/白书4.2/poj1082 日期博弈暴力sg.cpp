#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 
			  31, 31, 30, 31, 30, 31};
int dp[2010][13][32];

bool isleap(int year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

bool after(int y, int m, int d)
{
	return (y > 2001 || 
	       (y == 2001 && m > 11) || 
		   (y == 2001 && m == 11 && d > 4));
}

void nt(int &y, int &m, int &d)
{
	d += 1;
	int dlim = days[m - 1];
	if (m == 2) {
		if (isleap(y)) {
			dlim = 29;
		}
	}
	if (d > dlim) {
		d = 1;
		++ m;
	}
	if (m > 12) {
		m = 1;
		++ y;
	}
}

bool valid(int y, int m, int d)
{
	int dlim = days[m - 1];
	if (m == 2) {
		if (isleap(y)) {
			dlim = 29;
		}
	}
	return d <= dlim;
}

int dfs(int y, int m, int d)
{
	if (dp[y][m][d] != -1) {
		return dp[y][m][d];
	}
	if (y == 2001 && m == 11 && d == 4) {
		return dp[y][m][d] = 0;
	}
	if (after(y, m, d)) {
		return dp[y][m][d] = 1;
	}
	int ret = 1;
	int yy = y;
	int mm = m;
	int dd = d;
	nt(yy, mm, dd);
	ret &= dfs(yy, mm, dd);
	yy = y;
	mm = m;
	dd = d;
	++ mm;
	if (mm > 12) {
		mm = 1;
		++ yy;
	}
	if (valid(yy, mm, dd)) {
		ret &= dfs(yy, mm, dd);
	}
	return dp[y][m][d] = !ret;
}

int main()
{
	memset(dp, -1, sizeof dp);
	int t;
	scanf("%d", &t);
	while (t --) {
		int y, m, d;
		scanf("%d%d%d", &y, &m, &d);
		if (dfs(y, m, d)) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;	
}
