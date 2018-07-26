#include<iostream>  
#include<cstring>  
#include<cstdio> 
using namespace std;
 
// 数n!的质因子x的个数
int fact_prime(int n, int x)
{
	int res = 0;
	while (n)
	{
		res += n / x;
		n /= x;
	}
	return res;
}
 
// 定义 f(n) := n除以2^a*5^b，a和b分别是质因子2和5的个数
// f(1)...f(n)中以x(1 3 7 9)结尾的奇数的个数
int odd_end_with(int n, int x)
{
	if (n == 0) return 0;
	return n / 10					// 1.a 每10个数都有一个
		+ (n % 10 >= x)				// 1.b n的个位数可能产生一个
		+ odd_end_with(n / 5, x);	// 2.  迭代除以5，以满足5^b这个条件
}
 
// f(1)...f(n)中以x(1 3 7 9)结尾的数的个数
int end_with(int n, int x)
{
	if (n == 0) return 0;
	return end_with(n / 2, x)		// 1. 数列中的偶数，迭代以满足除以2^a这个条件
		 + odd_end_with(n, x);		// 2. 数列中的奇数
}
 
 
int table[4][4] = 
{
	6, 2, 4, 8,//2^4 2 2^2 2^3 的最后一位
	1, 3, 9, 7,//同理3
	1, 7, 9, 3,//同理7  
	1, 9, 1, 9,//同理9  
};
 
///////////////////////////SubMain//////////////////////////////////
int main(int argc, char *argv[])
{
	int n, m;
	while (~scanf("%d%d", &n, &m))
	{
		m = n - m;
		int two	= fact_prime(n, 2) - fact_prime(m, 2);
		int five	= fact_prime(n, 5) - fact_prime(m, 5);
		int three	= end_with(n, 3) - end_with(m, 3);
		int seven	= end_with(n, 7) - end_with(m, 7);
		int nine	= end_with(n, 9) - end_with(m, 9);
		if (two < five)
		{
			puts("5");
			continue;
		}
		int res = 1;
		if (two > five) res *= table[0][(two - five) % 4];
		res *= table[1][three % 4];
		res *= table[2][seven % 4];
		res *= table[3][nine  % 4];
		res %= 10;
		printf("%d\n", res);
	}
	return 0;
}
