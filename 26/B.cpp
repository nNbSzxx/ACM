#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
long long map[] = {9,18,162,324,2916,5832,52488,104976,944784,1889568,17006112,34012224,306110016,612220032,612220032LL * 9};

int main()
{
	int n;
	while (~scanf("%d",&n)) {
		int ans = 0;
		for (int i = 0; ; i ++) {
			if (n > map[i]) {
				ans ++;
			} else {
				break;
			}
		}
		if (ans % 2 == 0) {
			puts("Stan wins.");
		} else {
			puts("Ollie wins.");
		}
	}
}
