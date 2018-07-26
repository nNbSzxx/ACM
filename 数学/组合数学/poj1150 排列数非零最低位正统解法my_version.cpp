#include <cstdio>
#include <iostream>
using namespace std;
int n,m;
int table[4][4] = {
	6, 2, 4, 8,
	1, 3, 9, 7,
	1, 7, 9, 3,
	1, 9, 1, 9,
};
int getprime(int n, int x)
{
	int ret = 0;
	while (n) {
		ret += n / x;
		n /= x;
	}
	return ret;
}

int getodd(int n, int x)
{
	if (n == 0) return 0;
	return getodd(n / 5, x) + (n % 10 >= x) + (n / 10);
}
int getend(int n, int x)
{
	if (n == 0) return 0;
	return getend(n / 2, x) + getodd(n, x);
}

int main()
{
	while (~scanf("%d%d",&n,&m)) {
		m = n - m;
		int two = getprime(n,2) - getprime(m,2);
		int five = getprime(n,5) - getprime(m,5);
		int three = getend(n,3) - getend(m,3);
		int seven = getend(n,7) - getend(m,7);
		int nine = getend(n,9) - getend(m,9);
		int ans = 1;
		if (five > two) {
			puts("5");
			continue;
		}
		ans = ans * table[1][three % 4] % 10;
		ans = ans * table[2][seven % 4] % 10;
		ans = ans * table[3][nine % 4] % 10;
		if (two > five) {
			ans = ans * table[0][(two - five) % 4] % 10;
		}
		printf("%d\n",ans);
	}
}
