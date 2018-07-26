//Kobayashi
//
#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while (t --) {
		int n,a;
		int k = 0, t = 0; 
		scanf("%d",&n);
		for (int i = 1; i <= n ; i++) {
			scanf("%d",&a);
			switch (a) {
				case 1:
					++ k;
					break;
				case 2:
					++ t;
					break;
			}
		}
		if (k > t) {
			puts("Kobayashi");
		} else if (k < t) {
			puts("Tohru");
		} else {
			puts("Draw");
		}
	}
}
