#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <bitset>
using namespace std;
const int MAX = 1e6 + 10;
const int INF = 0x3f3f3f3f;
int n, father[MAX], c[MAX], item[MAX], num[MAX], it[MAX];
int cnt, k;
int dp[MAX];
map<int, int> mp;

int find(int x)
{
    while (x != father[x]) {
        father[x] = father[father[x]];
        x = father[x];
    }
    return x;
}
void merge(int x, int y)
{
    x = find(x);
    y = find(y);
    if (x != y) {
        father[x] = y;
        c[y] += c[x];
    }
    return ;
}

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 1; i <= n; i ++) {
        father[i] = i;
        c[i] = 1;
    }
    int a;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &a);
        merge(i, a);
    }
    int sum = 0;
    for (int i = 1; i <= n; i ++) {
        if (i == father[i]) {
            mp[c[i]] ++;
            sum ++;
        }
    }
 //   cout << sum << endl << endl;
    cnt = 0;
    for (map<int, int>::iterator it = mp.begin(); it != mp.end(); it ++) {
        num[cnt] = it -> second;
        item[cnt ++] = it -> first;
    }
//    cout << cnt << endl << endl;
    int icnt = 0;
    for (int i = 0; i < cnt; i ++) {
        int j = 1, nn = num[i];
        while (j <= nn) {
            nn -= j;
            it[icnt ++] = j * item[i];
            j <<= 1;
        }
        if (nn > 0) {
            it[icnt ++] = nn * item[i];
        }
    }
//	cout << icnt << endl << endl;
//	for (int i = 0; i < icnt ; i ++) {
//		cout << it[i] << endl;
//	}
	bitset<MAX> dp;
	dp[0] = 1;
    for (int i = 0; i < icnt; i ++) {
    	dp |= (dp << it[i]);
	}

    if (dp[k]) {
        printf("%d", k);
    } else {
        printf("%d", k + 1);
    }
    cout << " ";
    int ans = 0, kk = k, ssum = 0;
    for (int i = 0; i < cnt; i ++) {
    	while (num[i] --) {
    		if (kk >= item[i] / 2) {
    			kk -= item[i] / 2;
    			ans += item[i] / 2 * 2;
			} else {
				ans += 2 * kk;
				kk = 0;
				break;
			}
			if (item[i] & 1) ssum ++;
		}
		if (kk == 0) {
			break;
		}
	}
	ans += min(kk, ssum);
    printf("%d\n", ans);

    return 0;
}
