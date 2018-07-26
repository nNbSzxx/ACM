#include <bits/stdc++.h>
using namespace std;

int n, ro, re, oe; 
int main()
{
	scanf("%d%d%d%d", &n ,&ro, &re, &oe);
//	int 
//	if (re == ro + oe) {
//		
//	}
	-- n;
	int ans = 0;
	if (n == 0) {
		puts("0");
	} else
	if (n == 1) {
		ans = min(ro, re);
		printf("%d\n", ans);
	} else {
		if (n == 2) {
			ans = min(ro * 2, ro + oe);
			ans = min(re * 2, ans);
			ans = min(re + oe, ans);
			printf("%d\n", ans);
		} else {
//			ans = min(ro, oe);
			int temp = min(ro, oe);
			temp = min(temp, re);
			if (temp == ro) {
				ans = ro;
			} else if (temp == oe) {
				ans = min(ro, re);
			} else if (temp == re) {
				ans = re;
			}
			ans += (n - 1) * temp;
			printf("%d\n", ans); 
		}
	}
	return 0;
}
