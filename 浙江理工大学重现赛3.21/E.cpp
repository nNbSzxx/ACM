#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 10100;

long long gcd(long long a, long long b)
{
	long long r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	long long a,b;
	while (~scanf("%lld%lld",&a,&b)) {
		long long c = gcd(a,b);
		int flag = 1;
		while (a != 1) {
			long long cc = gcd(c,a);
			a /= cc;
			if (cc == 1 && a != 1) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			printf("No\n");
			continue;
		}
		while (b != 1) {
			long long cc = gcd(c,b);
			b /= cc;
			if (cc == 1 && b != 1) {
				flag = 0;
				break;
			}
		}
		if (!flag) {
			printf("No\n");
			continue;
		}
		printf("Yes\n");
	}
}
