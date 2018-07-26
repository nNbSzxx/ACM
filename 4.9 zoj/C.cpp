#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int day[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool isLeap(int x)
{
	if (x % 400 == 0 || (x % 4 == 0 && (x % 100 != 0))) {
		return true;
	}
	return false;
}
int count9 (int x)
{
	int t, cnt = 0;
	while (x) {
		t = x % 10;
		x /= 10; 
		if (t == 9) cnt ++;
	}
	return cnt;
}
int main()
{
	int t;
	scanf("%d",&t);
	int fy,fm,fd,ty,tm,td;
	while (t --) {
		scanf("%d%d%d%d%d%d",&fy,&fm,&fd,&ty,&tm,&td);
		int ans = 0;
		int dy = ty - fy - 1;

		if (dy < 0) dy = 0;

		
		if (ty - fy == 0 && tm - fm == 0) {
			for (int i = fd; i <= td; i ++) {
				if (i % 10 == 9) ans ++;
			}
			if (tm == 9) ans += td - fd + 1;
			ans += count9(ty) * (td - fd + 1);
			printf("%d\n",ans);
			continue;
		}
		
			if (fd <= 9) {
				ans += 3;
			} else {
				if (fd <= 19) {
					ans += 2;
				} else {
					if (fd <= 29) {
						ans += 1;
					}
				}
			}
			if (td >= 29) {
				ans += 3;
			} else {
				if (td >= 19) {
					ans += 2;
				} else {
					if (td >= 9) {
						ans += 1;
					}
				}
			}
			if (fm == 9) {
				ans += 30 - fd + 1;
			}
			if (tm == 9) {
				ans += td;
			}
	
		
		if (fy - ty == 0) {
			int cnt = count9(fy);
			bool isleap = isLeap(fy);
			for (int i = fm + 1; i <= tm - 1; i ++) {
				ans += 3;
				if (i == 9) ans += 30;
				if (i == 2 && !isleap) {
					ans --;			
				}
				ans += cnt * day[i];
				if (i == 2 && isleap) {
					ans += cnt;
				}
			} 
			ans += (day[fm] - fd + 1 + td) * cnt;
			if (fm == 2 && isleap) ans += cnt;
			printf("%d\n",ans);
			continue;
		}
		
		bool isleap = isLeap(fy);
		int cm = fm + 1;
		for (int i = cm; i <= 12; i ++) {
			if (i == 9) {
				ans += 30;
			}
			ans += 3;
			if (i == 2) {
				if (!isleap) {
					ans --;
				}
			}
		}
		
		isleap = isLeap(ty);
		cm = tm - 1;
		for (int i = 1; i <= cm; i ++) {
			if (i == 9) {
				ans += 30;
			}
			ans += 3;
			if (i == 2) {
				if (!isleap) {
					ans --;
				}
			}
		}
		
		ans += dy / 4;
		ans += dy * 35 + dy * 30;
		for (int i = 1; i <= dy % 4; i ++) {
			if (isLeap(fy + i)) ans ++;
		}
		int cnt = count9(fy);
		if (cnt) {
			isleap = isLeap(fy);
			for (int i = fm + 1; i <= 12; i ++) {
				ans += cnt * day[i];
				if (i == 2 && isleap) ans += cnt;
			}
			ans += (day[fm] - fd + 1) * cnt;
			if (fm == 2 && isleap) ans += cnt;
		}
		cnt = count9(ty);
		if (cnt) {
			isleap = isLeap(ty);
			for (int i = 1; i < tm; i ++) {
				ans += cnt * day[i];
				if (i == 2 && isleap) ans += cnt;
			}
			ans += (td) * cnt;
		}	
		for (int i = fy + 1; i <= ty - 1; i ++) {
			cnt = count9(i);
			if (cnt) {
				ans += cnt * 365;
				if (isLeap(i)) {
					ans += cnt;
				}
			}
		}

		printf("%d\n",ans);
	}
	
	
	return 0;
}
