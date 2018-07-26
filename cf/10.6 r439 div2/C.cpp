#include <bits/stdc++.h>
using namespace std;
const int MAX = 5010;
const long long mod = 998244353LL;
long long dp[MAX][MAX];

long long f(int x, int y)
{
	if (x == 0 || y == 0) return 1;
	if (dp[x][y] != 0) return dp[x][y];
	return dp[x][y] = (f(x - 1, y) + y * f(x - 1, y - 1) % mod) % mod;
}

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	cout << (f(a, b) * f(a, c) % mod * f(b, c) % mod) << endl;
}
