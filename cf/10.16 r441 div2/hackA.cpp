#include <bits/stdc++.h>
using namespace std;
int f[108][3];

int main()
{
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	f[0][0] = 0, f[0][1] = f[0][2] = 100000000;
	for (int i = 1; i < n; i ++) {
		f[i][0] = min(f[i - 1][1] + a, f[i - 1][2] + b);
		f[i][1] = min(f[i - 1][0] + a, f[i - 1][2] + c);
		f[i][2] = min(f[i - 1][0] + b, f[i - 1][1] + c);
	}
	if (f[n - 1][0] < f[n - 1][1])
		printf("%d\n", min(f[n - 1][0], f[n - 1][2]));
	else 
		printf("%d\n", min(f[n - 1][1], f[n - 1][2]));
}
