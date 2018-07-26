#include <iostream>
#include <algorithm>
#include <cstdio>
#include <string>
#include <cmath>
using namespace std;
const int mod = 998244353;

int factor(int x)
{
	if (x == 1) return 1;
	int sum = 2;
	for (int i = 2; i * 2 <= x; i ++) {
		if (x % i == 0) {
			++ sum;
		}
	}
	return sum;
}

int main()
{
	int n = 100;
	for (int k = 1; k <= 10; k ++) {
		int ans = 0;
		for (int i = 1; i <= n; i ++) {
			ans += factor(pow(i, k));
		}
		cout << "k: " << k << " " << ans << endl;
	}
	
	
	
	return 0;
}
