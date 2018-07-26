#include <cstdio>
#include <cstring>
using namespace std;
int sg[110][13][35];

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31,};
bool isLeap(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0) ;
}
bool isValid(int y, int m, int d)
{
	if (y > 2001) return false;
	if (y == 2001 && m > 11) return false;
	if (y == 2001 && m == 11 && d > 4) return false;
	if (m != 2) {
		if (d > month[m]) return false;
		else return true;
	} else {
		if (isLeap(y)) {
			if (d <= 29) {
				return true;
			} else {
				return false;
			}
		} else {
			if (d <= 28) return true;
			else return false;
		}
	}
}
int maxD (int yy, int mm, int dd)
{
	if (mm != 2) {
		return month[mm];
	} else {
		if (isLeap(yy)) {
			return 29;
		} else {
			return 28;
		}
	}
}
int dfsSG (int y, int m, int d)
{
	if (sg[y-1900][m][d] != -1) {
		return sg[y-1900][m][d];
	}
	int vis[3];
	memset(vis,0,sizeof(vis));
	int dd = d + 1;
	int mm = m;
	int yy = y;
	if (dd > maxD(yy,mm,dd)) {
		dd = 1;
		++ mm;
	}
	if (mm > 12) {
		mm = 1;
		++ yy;
	}
	if (isValid(yy,mm,dd)) {
		dfsSG(yy,mm,dd);
		vis[sg[yy-1900][mm][dd]] = 1;
	}
	dd = d;
	mm = m + 1;
	yy = y;
	if (mm > 12) {
		mm = 1;
		++ yy;
	}
	if (isValid(yy,mm,dd)) {
		dfsSG(yy,mm,dd);
		vis[sg[yy-1900][mm][dd]] = 1;
	}
	for (int i = 0; ; i ++) {
		if (!vis[i]) {
			return sg[y-1900][m][d] = i;
		}
	}
}

int main()
{
	int y,m,d;
	memset(sg,-1,sizeof(sg));
	sg[101][11][4] = 0;
	int t;
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d%d",&y,&m,&d);
		if (dfsSG(y, m, d)) {
			printf("YES\n");
//			printf("%d\n",dfsSG(y,m,d));
		} else {
			printf("NO\n");
		}
	}
}
