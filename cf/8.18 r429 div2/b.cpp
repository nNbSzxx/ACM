#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, a;
	cin >> n;
	int flag = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> a;
		if (a & 1) {
			flag = 1;
		}
	}
	if (flag) {
		puts("First");
	} else {
		puts("Second");
	}
}
