/*
translation:
    给出n个字符串，求一个最小长度的串，该串包含给出的所有字符串。注意该字符串在长度最小的同时还必须是字典序最小。
solution:
    状态压缩dp
    注意到n的值比较小，所以考虑可以状态压缩。定义dp[i][s]:=在所有字符串选取情况为s的情况下，最前面的字符串为i号字符串
    的最小长度。依次枚举下一个字符串可得状态转移方程 dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
    cost数组是j字符串前面接上i字符串所加上的最小长度。这个可以通过预处理得到。dp完毕后即可通过搜索来逐渐往后加字符串，
    最终得到答案。
note:
    # 一开始打算dp[i][s]来表示最后一个字符串是i，但是考虑到这样求最小的字典序不好求。所以将状态定义成最前面一个是i就很容易
      得出。
    # 注意如果给出的字符串i包含j，那么j字符串是需要去掉的。
date:
    2017.1.27(祝自己除夕快乐么么哒)
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
 
using namespace std;
const int maxn = 17;
const int INF = 0x3f3f3f3f;
 
int n, dp[maxn][1 << maxn];
string str[maxn], ans;
int cost[maxn][maxn]; //cost[i][j]表示将j字符串
 
void init()
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j && str[i].find(str[j]) != string::npos) {
				str[j] = str[i];
				//如果str[i]包含了str[j]
			}
		}
	}
	stable_sort(str, str + n);
	n = unique(str, str + n) - str;
 
	memset(cost, 0, sizeof(cost));
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            //j的前面接上i
            int len = min(str[i].length(), str[j].length());
            for(int k = 0; k <= len; k++) {
                if(str[i].substr(str[i].length() - k) == str[j].substr(0, k)) {
                    cost[i][j] = str[i].length() - k;
                }
            }
        }
	}
 
}
 
void dfs(int id, int s)
{
	if(s == 0)   return;
 
	string tmp; int next_id = -1;
	for(int i = 0; i < n; i++) if(i != id && (s >> i & 1)) {
        if(dp[id][s] == dp[i][s & ~(1 << id)] + cost[id][i]) {
            string t = str[i].substr(str[id].length() - cost[id][i], str[i].length());
            if(next_id == -1 || t < tmp) {
                tmp = t;
                next_id = i;
            }
        }
	}
	ans += tmp;
	dfs(next_id, s & ~(1 << id));
}
 
int main()
{
	//freopen("in.txt", "r", stdin);
	int T, kase = 0;
	cin >> T;
    while(T--) {
		cin >> n;
		for(int i = 0; i < n; i++)	cin >> str[i];
 
		if(n > 1) {
			init();
			for(int i = 0; i <= n; i++)	fill(dp[i], dp[i] + (1 << n), INF);
			for(int i = 0; i < n; i++) {
				dp[i][1 << i] = str[i].length();
			}
 
			for(int s = 0; s < 1 << n; s++) {
                for(int j = 0; j < n; j++) if(dp[j][s] != INF && (s >> j & 1)) {
                    for(int i = 0; i < n; i++) if(!(s >> i & 1)) {
                        dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
                    }
                }
			}
 
 
			int id = 0;
			for(int i = 1; i < n; i++) {
                if(dp[i][(1 << n) - 1] < dp[id][(1 << n) - 1]) {
                    id = i;
                }
			}
 
 
			ans = str[id];
			dfs(id, (1 << n) - 1);
		} else {
			ans = str[0];
		}
 
		cout << "Scenario #" << ++kase << ":" << endl;
		cout << ans << endl;    cout << endl;
    }
    return 0;
}
//ACCCGATACG AGTCATTTAAATTACGGATCGGATCTGTACCGTAGCCCGTTAGGCATGCAGC
//ACCCGATACG AGTCATTTAAATTACGGATCGGATCTGTACCGTAGCCCGTTAGGCATGCAGC
//ACCCGATACG TACCGAGTCATTTAAATTACGGATCGGATCTGTAGCCCGTTAGGCATGCAGC
