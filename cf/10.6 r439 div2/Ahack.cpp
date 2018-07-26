#include <iostream>
using namespace std;
const long long MAX = 1e18;

long long p(long long n)
{
	long long c = 0, m = 5;
	while (m < n) {
		c += n / m;
		m *= 5;
	}
	return c;
}

long long c(long long b, long long a)
{
	long long m = 1;
	while (a < b) {
		m = (m * (a + 1)) % 10;
		a ++;
	}
	return m;
}

int main()
{
//	freopen("a.in", "w", stdout);
//	cout << MAX << endl;
	long long a, b;
	while (cin >> a >> b)
	if (p(a) == p(b)) {
		cout << '=' << c(b, a) << endl;
	} else {
		cout << '!' << 0 << endl;
	}
	
}
