#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int tc = 1,t;
	scanf("%d",&t);
	int n,m,p;
	int a[100005], b[100005];
	while (t --) {
		scanf("%d%d%d",&n,&m,&p);
		int q;
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&a[i]);
		}
		for (int i = 1; i <= m; i ++) {
			scanf("%d",&b[i]);
		}
		int j = 1;
		int cnt = 0;
		for (int i = 1; i + (m-1) * p <= n; i ++) {
			int flag = 1;
			for (int j = 1; j <= m; j ++) {
				if (a[i + (j-1) * p] != b[j]) {
					flag = 0;
					break;
				} 
			}
			if (flag) {
				cnt ++;
			}
		}
		printf("Case #%d: ",tc ++);
		printf("%d\n",cnt);
	}
}
