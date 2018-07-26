#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
const int MAX = 1e5 + 10;
const int INF = 1e9 + 7;
int e[MAX];
int a, b, h, w ,n;
int ans;

bool cmp(int i1, int i2) 
{
	return i1 > i2;
}
void dfs(int x, int y, int cnt)
{
	if (x <= 1 && y <= 1) {
		ans = min(ans, cnt);
		return ;
	}
	if (cnt >= n) return ;
	if (e[cnt] == 2) {
		while (x > 1) {
			x = x / 2 + (x % 2);
			cnt ++;
		}
		while (y > 1) {
			y = y / 2 + (y % 2);
			cnt ++;
		}
		ans = min(ans, cnt);
		return ;
	}
	if (x > 1) dfs(x / e[cnt] + (x % e[cnt] > 0), y, cnt + 1);
	if (y > 1) dfs(x, y / e[cnt] + (y % e[cnt] > 0), cnt + 1);
	return ;
}
int main()
{

    cin >> a >> b >> h >> w >> n;
    for (int i = 0; i < n; i ++) {
        cin >> e[i];
    }
    if (a <= h && b <= w || a <= w && b <= h) {
        cout << 0 << endl;
        return 0;
    }
    sort(e, e + n, cmp);
    int aim1 = a / h + (a % h > 0);
    int aim2 = b / w + (b % w > 0);
    ans = n + 1;
	dfs(aim1, aim2, 0);
	aim1 = a / w + (a % w > 0);
    aim2 = b / h + (b % h > 0);
    dfs(aim1, aim2, 0);
	if (ans == n + 1) {
		cout << -1 << endl;
	} else {
		cout << ans << endl;
	}
    return 0;
}

