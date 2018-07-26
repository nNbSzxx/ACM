#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <bitset>
using namespace std;
const long MAX = 150010L;
bitset<MAX> map[MAX];
int main() 
{
	int n,m,u,v;
	memset(map,0,sizeof(map));
	scanf("%d%d",&n,&m);
	for (int i = 1; i <= n; i ++) {
		map[i][i] = 1;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d",&u,&v);
		map[u][v] = map[v][u] = 1;
	}
	int flag = 1;
	for (int k = 1 ; k <= n; k ++) {
		for (int i = 1; i <= n; i ++) {
			if (map[i][k]) {
				if (map[i] != (map[i] | map[k])) {
					flag = 0;
					goto A;
				}
			}
		}
	}
	A:
	if (flag) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	
	return 0;
} 
