#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
	int t = 1;
	int m;
	while (cin >> m) {
		int ans = m * log10(2);
		cout << "Case #" << t ++ <<  ": ";
		cout << ans << endl;
	}

	return 0;
}
