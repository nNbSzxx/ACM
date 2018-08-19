#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n;
char s[MAX];
int cnt[300];

int main()
{
	scanf("%d", &n);
	scanf(" %s", s);
	bool ok = false;
	for (int i = 0; i < n; i ++) {
		++ cnt[s[i]];
	}
	if (n == 1) {
		puts("Yes");
		return 0;
	}
	for (int i = 'a'; i <= 'z'; i ++) {
		if (cnt[i] >= 2) {
			ok = true;
			break;
		}
	}
	if (ok) {
		puts("Yes");
	} else {
		puts("No");
	}
	return 0;
} 
