#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	int n,m;
	while (~scanf("%d%d",&n,&m), n || m) {
		if (n < m) {
			n = n ^ m;
			m = n ^ m;
			n = n ^ m;
		}
		if (n % m == 0 || n / m >= 2) {
			printf("Stan wins\n");
			continue;
		}
		int flag = 0;
		while (m) {
			n -= m;
			if (n < m){
				n = n ^ m;
				m = n ^ m;
				n = n ^ m;
			}
			flag = ~flag;
			if (n / m >= 2 || n % m == 0) {
				flag = ~flag;
				break;
			}
		}
		if (flag) {
			printf("Stan wins\n");
		} else {
			printf("Ollie wins\n");
		}
	}
	return 0;
}
