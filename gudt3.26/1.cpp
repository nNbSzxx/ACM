#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int a,b,c;
		int ans = 0;
		scanf("%d%d%d",&a,&b,&c);
		printf("%d\n",b+a/2-c/4);
	}
	return 0;
 } 
