#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 10;
int a, b, f, k;

int main()
{
	cin >> a >> b >> f >> k;
	int maxx = max(f, a - f);
	int minn = min(f, a - f);
	if (k == 1) {
		if (b < f || b < a - f) {
			puts("-1");
			return 0;
		} else {
			if (b >= a) {
				puts("0");
			} else {
				puts("1");
			}
		}
		return 0;
	}
	if (k == 2) {
		if (b < f || b < 2 * (a - f)) {
			puts("-1");
			return 0;
		}
	}
	if (k >= 3 && maxx * 2 > b) {
		puts("-1");
		return 0;
	}
	int nowb = b;
	int ans = 0;
	
	if (nowb < f + (a - f) * 2) {
		++ ans;
		nowb = b;
	} else {
		nowb -= f;
	}
	
	int state = -1;
	for (int i = 1; i < k - 1; i ++) {
		if (state) {
			state = ~state;
			nowb -= (a - f) * 2;
			if (nowb < 2 * f) {
				++ ans;
//				cout << i << " " << nowb << endl;
				nowb = b;
			} else {
				;
			}
		} else {
			state = ~state;
			nowb -= (f) * 2;
			if (nowb < 2 * (a - f)) {
				++ ans;
//				cout << i << " " << nowb << endl;
				nowb = b;
			}
		}
	}
//	cout << nowb << endl;
	state = ~state;
	if (state) {
		nowb -= 2 * f;
		if (nowb < a - f) ++ ans;
	} else {
		nowb -= 2 * (a - f);
		if (nowb < f) ++ ans;
	}
	
	printf("%d\n", ans);
}
