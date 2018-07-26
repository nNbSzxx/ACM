#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
using namespace std;

const int MAX = 76923078;

bool isTrue(int n)
{
	char s[15];
	itoa(n * 13, s, 10);
	if (strstr(s,"13")) {
		return true;
	} else {
		return false;
	}
}

int main()
{
	int f[MAX] = {0};
	f[1] = 1;
	for (int i = 2; i <= MAX; i ++) {
		if(isTrue(i)) {
			f[i] = f[i - 1] + 1;
		} else {
			f[i] = f[i - 1];
		}
	}

	int n;
	while (~scanf("%d",&n)) {
		printf("%d\n",f[n / 13]);
	}
	return 0;
}
