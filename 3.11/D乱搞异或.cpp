#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cmath>
using namespace std;
const int INF = 0x3f3f3f3f;
struct qu{
	int begin;
	int end;
	int v;
};
int main()
{
	int n;
	int f1[64100],f2[64100];
	int m;
	int x,y;
		int v;
	qu q[64100];
	while (~scanf("%d",&n) ) {
		memset(f1,0,sizeof(f1));
		memset(f2,0,sizeof(f2));
		for (int i = 1; i <= n; i ++) {
			
			scanf("%d%d",&x,&y);
			x += 32000;
			y += 32000;
		
			scanf("%d",&v);
			for (int j = x; j < y; j ++) {
				f1[j] = v;
				if (!v) {
					f1[j] = 101;
				}
			}
		}
	
		scanf("%d", &m);
		for (int i = 1; i <= m; i ++) {
			scanf("%d%d%d",&x,&y,&v);
			x += 32000;
			y += 32000;
			for (int j = x; j < y; j ++) {
				f2[j] = f1[j];
			}
		}
		int cnt = 0,flag = 0,cv;
		for (int i = 0; i <= 64005; i ++) {
			f1[i] ^= f2[i];
			if (f1[i] && !flag) {
				q[++cnt].begin = i;
				q[cnt].v = cv = f1[i];
				flag = 1;
			}
			if ( (f1[i] ^ cv) && flag) {
				q[cnt].end = i ;
				flag = 0;
				if (f1[i]) {
					q[++ cnt].begin = i;
					q[cnt].v = cv = f1[i];
					
					flag = 1;
				}
			}
		}
//		for (int i = 0 + 32000; i <= 10 + 32000; i ++) {
//			printf("%d ",f1[i]);
//		}
//		printf("\n");
//		for (int i = 0 + 32000; i <= 10 + 32000; i ++) {
//			printf("%d ",f2[i]);
//		}
//		printf("\n");
	
		printf("%d",cnt);
	//	printf("\n");
		for (int i = 1; i <= cnt ; i ++) {
			if (q[i].v ^ 101)
				printf(" %d %d %d",q[i].begin - 32000,q[i].end - 32000,q[i].v);
			else 
				printf(" %d %d %d",q[i].begin - 32000,q[i].end - 32000,0);
		}
		printf("\n");
	}
	return 0;
}
