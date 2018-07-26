#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <stack>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 3000005;
int main()	
{
	int t;

	unsigned long long f[MAX];
	for (int i = 0; i < MAX ; i ++) {
		f[i] = i;
	}
	for (int i = 2; i < MAX; i ++) {
		if (f[i] == i)
			for (int j = i; j < MAX; j += i) {
				f[j] = f[j] / i * (i - 1);
			}
	}

	int a,b;
	while (~scanf("%d%d",&a,&b)) {
		
		unsigned long long ans = 0;
		for (int i = a; i <= b; i ++) {
			ans += f[i];
		}
		printf("%llu\n",ans);
	}
	
	return 0;
}
