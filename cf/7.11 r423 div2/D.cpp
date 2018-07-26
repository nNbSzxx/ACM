#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;

int main()
{
	int n, k;
	std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    cin >> n >> k;
	int notExit = n - k;
	int linknodenum = notExit - 1;
	if (linknodenum < k) {
		if (linknodenum == 0) {
			cout << 2 << endl;
			for (int i = 1; i <= n - 1; i ++) {
				cout << 1 << " " << i + 1 << endl;
			}
			return 0;
		} else if (linknodenum == 1) {
			cout << 3 << endl;
			cout << 1 << " " << 2 << endl;
			cout << 1 << " " << 3 << endl;
			for (int i = 1; i <= n - 3; i ++) {
				cout << 2 << " " << i + 3 << endl;
			}
			return 0;
		} else {
			cout << 4 << endl;
			for (int i = 1; i <= linknodenum; i ++) {
				cout << 1 << " " << i + 1 << endl;
			}
			for (int i = 1; i <= linknodenum; i ++) {
				cout << i + 1 << " " << i + linknodenum + 1 << endl;
			}
			for (int i = linknodenum + 1; i <= k; i ++) {
				cout << 2 << " " << i + linknodenum + 1 << endl;
			}
			return 0;
		}
	}
	int len = linknodenum / k  + 1;
	int numlongest = linknodenum % k;
	int linknum = k;
	if (numlongest == 0) {
		cout << 2 * len << endl;
	} else if (numlongest == 1) {
		cout << 2 * len + 1 << endl;
	} else {
		cout << 2 * len + 2 << endl;
	}
	int num = 1;
	for (int i = 1; i <= k; i ++) {
		++ num;
		int add = 0;
		if (numlongest > 0) add = 1; 
		for (int j = 1; j <= len + add; j ++) {
			if (j == 1) {
				cout << 1 << " " << num << endl;
			} else {
				cout << num << " " << num + 1 << endl;
				num ++;
			}
		}
		numlongest --;
	}
	return 0;
}
