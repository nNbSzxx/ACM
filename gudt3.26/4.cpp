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
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("%lld\n",a*b+c*(a/30));
	}
	return 0;
 } 
