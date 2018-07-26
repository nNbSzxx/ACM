#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int main() 
{
	int map[10009][2];
	int n,m;
	scanf("%d%d",&n,&m);
	int issafe = 1;
	for (int i = 1; i <= m; i ++) {
		int k;
		scanf("%d",&k);
		memset(map,0,sizeof(map));
		int flag = 0;
		for (int j = 1; j <= k; j ++) {
			int temp;
			scanf("%d",&temp);
			if (temp < 0) {
				temp *= -1;
				map[temp][0] = 1;
			} else {
				map[temp][1] = 1;
			}
			if (map[temp][0] && map[temp][1]) {
				flag = 1;
			}
		}
		if (!flag) {
			issafe = 0; 
		}
	}
	if (issafe) {
		printf("NO\n");
	} else {
		printf("YES\n");
	}
	
	return 0;
} 
