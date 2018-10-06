//IT'S WRONG!! AC for the weak test data !!

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
const int MAX = 200005;
const int mod = 10007;

int main()
{
	int t;
	char s[MAX];
	int nt[MAX];
	scanf("%d",&t);
	while (t --) {
		int n;
		scanf("%d",&n);
		scanf(" %s",s);
		int i = 0;
		int j = -1;
		nt[0] = -1;
		int ans = n % mod ;
		while (i < n) {
			if (j == -1 || s[i] == s[j]) {
				if (j != -1) {
					ans ++; 
					if (ans > mod)
						ans -= mod;
				}
				nt[ ++ i] = ++ j;
			} else {
				j = nt[j];
			}
		}
		printf("%d\n",ans);
		
	}
}
