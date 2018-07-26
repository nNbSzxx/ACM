#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

bool he(int n)
{
	int sum = 0;
	for (int i = 1; i <= n; i ++) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (sum & 1) {
		return false;
	} else {
		return true;
	}
}
int main()
{
	int n;
	while (~scanf("%d",&n)) {
		int sum = 0;
		for (int i = 1; i <= n; i ++) {
			if (!he(i)) {
				printf("%d ",i);
			}
		}
	}
}
