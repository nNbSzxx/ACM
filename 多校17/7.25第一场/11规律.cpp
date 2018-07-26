#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int t = 1;
	long long n, k;
	while (cin >> n >> k) {
		int ans;
		long long m = k % (n - 1);
		if (m == 0) {
			m = n - 1;
		}
		long long cir = k / (n - 1) + (k % (n - 1) > 0);
		if (m == 1) {
			if (cir == 1) {
				ans = 1;
			} else if (cir & 1) {
				ans = n - 1;
			} else {
				ans = n;
			}
		} else {
			if (cir == 1) {
				ans = m;
			} else {
				ans = m - 1;
			}
		}
		cout << "Case #" << t ++ <<  ": ";
		cout << ans << endl;
	}

	return 0;
}
