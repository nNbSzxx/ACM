#include <cstdio>
#include <cstring>
using namespace std;
const int mod = 1e9 + 7;
const int MAX = 1e6+10;
char s[MAX];
	int cntb[MAX];
int main()
{
	while (~scanf("%s",s)) {
		int len = strlen(s);
		int lenn = -1;
//		memset(cntb,-1,sizeof(cntb));
		for (int i = len - 1; i >= 0; i --) {
			if (s[i] == 'b') {
				lenn = i;
				break;
			}
		}
		int cnt = 1;
		int ans = 0;
		int cntb = 0;
		for (int i = lenn; i >=0; i --) {
			if (s[i] == 'b') {
				cntb ++;
			} else {
				ans = (ans + cntb) % mod;
				cntb = (2 * cntb) % mod;
			}
		}
//		int cnta = 0;
//		for (int i = lenn; i >= 0; i --) {
//			if (s[i] == 'b') {
//				++ cnt;
//			} else {
//				cntb[i] = cnt;
//				++ cnta;
//			}
//		}
//		cnt = 0;
//		for (int i = lenn; i >= 0; i --) {
//			if (s[i] == 'a') {
//				-- cnta;
//				ans = (ans + cntb[i]) % mod;
//				ans = (ans + cnta) % mod;
//				
//				if (!cnta) {
//					break;
//				}
//			}
//		}
		printf("%d\n",ans);
	}
}
