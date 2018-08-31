/*
translation:
    ����n���ַ�������һ����С���ȵĴ����ô����������������ַ�����ע����ַ����ڳ�����С��ͬʱ���������ֵ�����С��
solution:
    ״̬ѹ��dp
    ע�⵽n��ֵ�Ƚ�С�����Կ��ǿ���״̬ѹ��������dp[i][s]:=�������ַ���ѡȡ���Ϊs������£���ǰ����ַ���Ϊi���ַ���
    ����С���ȡ�����ö����һ���ַ����ɵ�״̬ת�Ʒ��� dp[i][s | 1 << i] = min(dp[i][s | 1<< i], dp[j][s] + cost[i][j]);
    cost������j�ַ���ǰ�����i�ַ��������ϵ���С���ȡ��������ͨ��Ԥ����õ���dp��Ϻ󼴿�ͨ����������������ַ�����
    ���յõ��𰸡�
note:
    # һ��ʼ����dp[i][s]����ʾ���һ���ַ�����i�����ǿ��ǵ���������С���ֵ��򲻺������Խ�״̬�������ǰ��һ����i�ͺ�����
      �ó���
    # ע������������ַ���i����j����ôj�ַ�������Ҫȥ���ġ�
date:
    2017.1.27(ף�Լ���Ϧ����ôô��)
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
int cost[maxn][maxn]; //cost[i][j]��ʾ��j�ַ���
 
void init()
{
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			if(i != j && str[i].find(str[j]) != string::npos) {
				str[j] = str[i];
				//���str[i]������str[j]
			}
		}
	}
	stable_sort(str, str + n);
	n = unique(str, str + n) - str;
 
	memset(cost, 0, sizeof(cost));
	for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) if(i != j) {
            //j��ǰ�����i
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
