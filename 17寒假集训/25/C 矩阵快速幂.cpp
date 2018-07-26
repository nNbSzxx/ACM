#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;
const unsigned long long mod = 2147493647ULL;

struct node {
	long long num[8][8];
	node (long long m[8][8]) 
	{
		for (int i = 0; i <= 7 ; i ++) {
			for (int j = 0 ; j <= 7; j ++) {
				num[i][j] = m[i][j];
			}
		}
	}
	node (int n)
	{
		for (int i = 0; i <= 7; i ++) {
			for (int j = 0; j <= 7; j ++) {
				num[i][j] = 0;
			}
		}
	}
	node () {
	}
};

node mul(node &m1, node &m2)
{
	node ans(0);
	for (int i = 1; i <= 7; i ++) {
		for (int j = 1; j <= 7; j ++) {
			for (int k = 1; k <= 7; k ++) {
				ans.num [i][j] = (ans.num[i][j] + (m1.num[i][k] % mod) * (m2.num[k][j] % mod)) % mod;
			}
		}
	}
	return ans;
}

node cal(node base, int r)
{
	node ans;
	for (int i = 1; i <= 7; i ++) {
		for (int j = 1; j <= 7; j ++) {
			ans.num[i][j] = (i == j);
		}
	}
	while (r) {
		if ( r & 1) {
			ans = mul(ans , base);
		}
		base = mul(base, base);
		r >>= 1;
	}
	return ans;
}

int main()
{
//	printf("%lld\n",mod);
	int t;
	scanf("%d", &t);
	int a,b,n;
	long long m[8][8] = {
		0,0,0,0,0,0,0,0,
		0,1,1,0,0,0,0,0,
		0,2,0,0,0,0,0,0,
		0,1,0,1,0,0,0,0,
		0,4,0,4,1,0,0,0,
		0,6,0,6,3,1,0,0,
		0,4,0,4,3,2,1,0,
		0,1,0,1,1,1,1,1,	
	};
	while (t --) {
		node base(m);
		scanf("%d",&n);
		scanf("%d%d", &a, &b);
		long long now[8] = {0, b % mod, a % mod, 16, 8, 4, 2, 1};
		base = cal(base , n - 2);
		long long ans = 0;
		for (int i = 1; i <= 7; i ++) {
			ans = (ans % mod + now[i] % mod * base.num[i][1] % mod) % mod;
		}
		printf("%llu\n", ans);
	}
	return 0;
	
}
