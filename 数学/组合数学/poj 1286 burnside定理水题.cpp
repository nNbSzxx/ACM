#include <iostream>
using namespace std;
int n;
long long ans[25], pow3[25];

int gcd(int a, int b)
{
	int r;
	while (b) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void table()
{
	ans[0] = 0; pow3[0] = 1;
	for (int i = 1; i < 24; i ++) {
		pow3[i] = 3 * pow3[i - 1];
		// ·­×ªÖÃ»» 
		if (i & 1)
			ans[i] = (1LL * i * pow3[(i + 1) / 2]);
		else 
			ans[i] = (1LL * i / 2 * pow3[(i / 2)] + 1LL * i / 2 * pow3[i / 2 + 1]);
		// Ðý×ªÖÃ»» 
		for (int j = 0; j < i; j ++) {
			ans[i] += (pow3[gcd(i, j)]);
		}
		ans[i] /= 2 * i;
		//cout << i << " " << pow3[i] << " " << 3LL * (i - 1) << " " << endl;  
	}
}

int main()
{
	table();
	while (cin >> n, n != -1) {
		cout << ans[n] << endl;
	}
}
