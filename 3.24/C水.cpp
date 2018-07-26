#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() 
{
	int n,m;
	while (~scanf("%d%d",&n,&m)) {
		int ans = 0;
		while (n <= m) {
			n *= 3;
			m *= 2;
			ans ++;
		}
		printf("%d\n",ans);	
	}
	
	return 0;
} 
