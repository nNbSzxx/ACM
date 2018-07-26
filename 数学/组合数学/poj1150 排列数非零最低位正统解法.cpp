#include<iostream>  
#include<cstring>  
#include<cstdio> 
using namespace std;
 
// ��n!��������x�ĸ���
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
 
// ���� f(n) := n����2^a*5^b��a��b�ֱ���������2��5�ĸ���
// f(1)...f(n)����x(1 3 7 9)��β�������ĸ���
int odd_end_with(int n, int x)
{
	if (n == 0) return 0;
	return n / 10					// 1.a ÿ10��������һ��
		+ (n % 10 >= x)				// 1.b n�ĸ�λ�����ܲ���һ��
		+ odd_end_with(n / 5, x);	// 2.  ��������5��������5^b�������
}
 
// f(1)...f(n)����x(1 3 7 9)��β�����ĸ���
int end_with(int n, int x)
{
	if (n == 0) return 0;
	return end_with(n / 2, x)		// 1. �����е�ż�����������������2^a�������
		 + odd_end_with(n, x);		// 2. �����е�����
}
 
 
int table[4][4] = 
{
	6, 2, 4, 8,//2^4 2 2^2 2^3 �����һλ
	1, 3, 9, 7,//ͬ��3
	1, 7, 9, 3,//ͬ��7  
	1, 9, 1, 9,//ͬ��9  
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
