#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e3 + 10;
char s[MAX];

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i ++) {
		scanf("%*d%*d");
	}
	for (int i = 0; i < n; i ++) {
		s[i] = (i & 1)? '0' : '1';
	}
	puts(s);
	return 0;
}
