#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int mov[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int main()
{
	int t,n,m,a[55][55];
	scanf("%d",&t);
	while (t --) {
		int sum = 0;
		scanf("%d%d",&n,&m);
		memset(a,0,sizeof(a));
		for (int i =  1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				scanf("%d",&a[i][j]);
			}
		}
		
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= m; j ++) {
				if (a[i][j]) {
					sum ++;
				}
				for (int k = 0; k <= 3; k ++) {
					int ii = i + mov[k][0];
					int jj = j + mov[k][1];
//					if (ii > 0 && ii <= n && jj > 0 && jj <= m) {
						if (a[i][j] > a[ii][jj]) {
							sum += a[i][j] - a[ii][jj];
						}
//					} 
					
				}
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
