#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
	int n, k;
	cin >> n >> k;
	if (n <= 3 || k == 1 || k >= 4) {
		cout << -1 << endl;
		return 0;
	}
	if (k == 2) {
		if (n == 4) {
			cout << -1 << endl;
			return 0;
		}
		printf("%d\n", n - 1);
		for (int i = 1; i < n; i ++) {
			printf("%d %d\n", i, i + 1);
		}
		return 0;
	}
	if (k == 3) {
		printf("%d\n", n - 1);
		for (int i = 1; i < 3; i ++) {
			printf("%d %d\n", i, i + 1);
		}
		for (int i = 4; i <= n; i ++) {
			printf("%d %d\n", 3, i);
		}
		return 0;;
	}
	return 0;
}


