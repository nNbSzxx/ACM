#include <bits/stdc++.h>
using namespace std;

int main()
{
	int l, r, a;
	scanf("%d%d%d", &l, &r, &a);
	int ans = 0;
	if (l - r >= a) 
		ans = (r + a) * 2;
	else if (r - l >= a)
		ans = (l + a) * 2;
	else {
		if (l < r) swap(l, r);
		int d = l - r;
		if ((d + a) & 1) 
			-- a;
		int b = a - d;
		ans = (l * 2 + b);
	}
	printf("%d\n", ans);
	
	return 0;
}
