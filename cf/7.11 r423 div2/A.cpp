#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n, a, b;
	cin >> n >> a >> b;
	int tot = 0;
	int p;
	int bb = 0;
	for (int i = 1; i <= n; i ++) {
		cin >> p;
		if (p == 1) {
			if (a) {
				a --;
			} else if (b) {
				b --;
				bb ++;
			} else if (bb) {
				bb --;
			} else {
				tot ++;
			}
		} else if (p == 2) {
			if (b) {
				b --;
			} else {
				tot += 2;
			}
		}
	}
	cout << tot << endl;
	
	return 0;
}
