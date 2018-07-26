#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
int t,n,p;

long long f(int n)
{
	long long ret = 1;
	int div = 2;
	while (div * div <= n) {
		int add = 1;
		while (n % div == 0) {
			n /= div;
			add ++;
		}
		ret *= add;
		div ++;
		if (ret > p) return -1;
	}
	if (n != 1) {
		ret *= 2;
	}
	return ret;
}

int main()
{	
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d",&n,&p);
		if (n == 1) {
			if (p == 1) {
				printf("YES\n");
			} else {
				printf("NO\n");
			}
			continue;
		}
//		if (p > sqrt(n)) {
//			printf("NO\n");
//			continue;
//		}
		
		if (f(n) == p) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
}
