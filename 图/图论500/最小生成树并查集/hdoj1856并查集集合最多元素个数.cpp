#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstdio>
using namespace std;
const int MAX = 10000005;
int father[MAX];
int num[MAX];
int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void unite(int a, int b)
{
	a = find(a);
	b = find(b);
	if (a != b) {
		father[a] = b;
		num[b] += num[a];
	}
	
	return ;
}
int main()
{
	int n;
	while (~scanf("%d",&n)) {
		for (int i = 1; i <= MAX - 5; i ++) {
			father[i] = i;
			num[i] = 1;
		}
		int a,b;
		for (int i = 1; i <= n; i ++) {
			scanf("%d%d",&a,&b);
			unite(a, b);
		}
		int ans = 0;
		for (int i = 1; i <= MAX - 5; i ++) {
			ans = (ans < num[i])? num[i] : ans;
		}
		printf("%d\n",ans);
	}
	return 0;
}
