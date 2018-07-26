#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
	long long n, k;
	cin >> n >> k;
	long long ans = n / k;
	if (ans & 1) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
	return 0;
}
