#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int table[4][4] = {
	6,2,4,8,
	1,3,9,7,
	1,7,9,3,
	1,9,1,9,
};

int getprime( int n, int x)
{
	int ret = 0;
	while (n) {
		ret += n / x;
		n /= x;
	}
	return ret;
 } 
int getodd (int n, int x)
{
	if (n == 0) {
		return 0;
	} else {
		return (n / 10) + (n % 10 >= x) + getodd(n / 5, x);
	}
}
int getend (int n, int x)
{
	if (n == 0) return 0;
	return getend(n / 2, x) + getodd(n, x);
}
int main()
{
	while (~scanf("%d%d",&n,&m)) {
		int two = getprime(n, 2) - getprime(m, 2) - getprime(n - m, 2);
		int five = getprime(n, 5) - getprime(m, 5) - getprime(n - m, 5);
		if (five > two) {
			puts("5");
			continue;
		}
		int three = getend(n, 3) - getend(m, 3) - getend(n - m, 3);
		int seven = getend(n, 7) - getend(m, 7) - getend(n - m, 7);
		int nine = getend(n, 9) - getend(m, 9) - getend(n - m, 9);
		three += 2 * nine; nine = 0; // 分母的3可能比分子多！ 
		int ans = 1;
		ans *= table[1][three % 4];
		ans *= table[2][seven % 4];
		ans *= table[3][nine % 4];
		if (two > five) {
			ans *= table[0][(two - five) % 4];
		}
		printf("%d\n",ans % 10);
	}
	return 0;
}
