#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main()
{
	int n;
	char s[510][510];
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		scanf(" %s", s[i]);
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i ++) {
		for (int j = 1; j < n - 1; j ++) {
			if (s[i][j] == 'X') {
				if (s[i - 1][j - 1] == 'X' && s[i - 1][j + 1] == 'X' 
										   && s[i + 1][j - 1] == 'X'
				                           && s[i + 1][j + 1] == 'X') {
					++ ans;                           	
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
