#include <iostream>
#include <algorithm> 
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 3e5 + 10;
char s1[MAX], s2[MAX];
int main()
{
	int t ;
	int n, x, y;
	while (~scanf("%d", &t)) {
		for (int i = 1; i <= t; i ++) {
			scanf("%d%d%d", &n ,&x, &y);
			scanf(" %s %s", s1, s2);
			int len = strlen(s1);
			int dif = 0;
			for (int i = 0; i < len; i ++) {
				if (s1[i] != s2[i]) {
					++ dif;
				}
			}
			int same = len - dif;
			
			if (dif < abs(x - y) || x > n || y > n || (x + y) > (n + same)) {
				puts("Lying");
			} else {
				puts("Not lying");
			}
		}
	}
	return 0;
}
