#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
	int a, b;
	while (~scanf("%d%d", &a, &b), a || b) {
		int now = 0;
		if (a < b) {
			swap(a, b);
		}
		while (true) {	
			if (a % b == 0) {
				break;
			}
			if (a / b >= 2) {
				break;
			}
			a -= b;
			swap(a, b);
			now ^= 1;
		}
		if (now == 0) {
			puts("Stan wins");
		} else {
			puts("Ollie wins");
		}
	}
	return 0;
}
