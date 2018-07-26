#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5 + 10;
set<int> s[2];
char str[MAX];
int len, cnt0 = 0, cnt1 = 0;
vector<int> ans[MAX];

int main()
{
	scanf(" %s", str);
	len = strlen(str);
	for (int i = 0; i < len; i ++) {
		if (str[i] == '0') {
			cnt0 ++;
			s[0].insert(i);
		} else {
			s[1].insert(i);
			cnt1 ++;
		}
	}
	if (cnt1 >= cnt0) {
		puts("-1");
		return 0;
	}
	int cnt = 0;
	while (!s[0].empty()) {
		int loc = -1, st = 0;
		while (1) {
//			printf("loc:%d st:%d\n", loc, st);
			auto it = s[st].lower_bound(loc);
			if (it == s[st].end()) {
				if (st == 0) {
					ans[cnt].pop_back();
					s[1].insert(loc);
				}
				++ cnt;
				break;
			} else {
//				printf("it:%d\n", *it);
				ans[cnt].push_back(*it);
				loc = *it;
				s[st].erase(it);
				st = !st;
			}
		}
		if (s[1].empty()) {
			while (!s[0].empty()) {
				ans[cnt ++].push_back(*(s[0].begin()));
				s[0].erase(s[0].begin());
			}
		}
	}
	if (s[1].size()) {
		puts("-1"); 
	} else {
		printf("%d\n", cnt);
		for (int i = 0; i < cnt; i ++) {
			printf("%d ", ans[i].size());
			for (auto a : ans[i])
				printf("%d ", a + 1);
			puts("");
		}
	}
	
	return 0;
}
