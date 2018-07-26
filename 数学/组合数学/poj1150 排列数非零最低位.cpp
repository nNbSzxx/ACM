#include <iostream>
#include <cstdio>
using namespace std;

int table[4] = {6, 2, 4, 8};
int step[10] = {0,0,1,-1,2,-1,0,1,-1,2};	
const int mod = 4;

int getstep(int x)
{
	int s = 0;
	while (x) {
		s = (s + x / 5) % mod;
		if (x % 5 == 2) s = (s + 1) % mod;
		if (x % 5 == 4) s = (s + 2) % mod;
		x /= 5;
	}
	return s;
}

int main()
{
	int n,m;

	while (~scanf("%d%d",&n,&m)) {
		if (n <= 1 || m == 0) {
			printf("1\n");
		} else if (m == 1) {
			printf("%d\n",n);	
		} else {
			printf("%d\n",table[(getstep(n) + 4 - getstep(n - m)) % mod]);
//			printf("%d %d %d\n",getstep(n), ss, mod);
//			printf("%d\n", -1 % 4);
		}
	}
	return 0;
} 


//int main()
//{
//	int n,m;
//	long long ans;
//	while (~scanf("%d%d",&n,&m)) {
//		ans = 1; 
//		for (int i = n; i >= n - m + 1; i --) {
//			ans *= i;
//			while (ans % 10 == 0) {
//				ans /= 10;
//			}
//		}
//		printf("%d\n",ans % 10);
//	}
//	return 0;
//}
