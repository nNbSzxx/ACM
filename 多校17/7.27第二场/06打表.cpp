#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring> 
using namespace std;
const int MAX = 1e3 + 5;
long long f[MAX][MAX];

int main()
{
	memset(f, 0, sizeof f);
	f[1][1] = f[1][2] = 1;
	for (int i = 3; i < MAX; i ++) {
		f[1][i] = f[1][i - 1] + 2 * f[1][i - 2];
	}
	for (int k = 2; k <= 3; k ++) {
		for (int i = 2; i < MAX; i ++) {
			for (int j = 1; j < MAX; j ++) {
				for (int l = j; l < j + k; l ++) {
					f[i][j] += f[i - 1][l];
				}
			}
		}
		cout << "k = " << k << endl;
		for (int i = 1; i <= 10; i ++) {
			cout << "i = " << i << endl;
			for (int j = 1; j <= 10; j ++) {
				cout << f[i][j] << " ";
			}
			cout << endl;
		}
	}
	
	return 0;
}
