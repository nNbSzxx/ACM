#include <iostream>
#include <cstring>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		if (n % 10 == 0) {
			puts("2");
		} else {
			puts("1");
		}
	}
	return 0;
}
