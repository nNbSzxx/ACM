#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 65530000;
const int T = 1e7;
int main()
{
	int dis[MAX];
	int a,b,c,d;
	while (~scanf("%d%d%d%d",&a,&b,&c,&d)) {
		memset(dis,0,sizeof(dis));
		for (int i = 0; i <= T; i ++) {
			if (b+i*a < MAX)
				dis[b+i*a] = 1;
			else
				break;
		}
		int flag = 1;
		for (int i = 0; i <= T; i ++) {
			if (d+i*c >= MAX)
				break;
			if (dis[d+i*c]) {
				printf("%d\n",d+i*c);
				flag = 0;
				break;
			}
		}
		if (flag) {
			printf("-1\n");
		}
	}
}

