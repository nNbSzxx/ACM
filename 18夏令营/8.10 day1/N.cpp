#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int MAX = 1e3 + 10;
char s[MAX];
int n;
map<char, int> cnt;
set<string> st;

int main()
{
	scanf("%d", &n);
	for (int i= 1; i <= n; i ++) {
		scanf(" %s", s);
		int len = strlen(s);
		cnt.clear();
		for (int i = 0; i < len; i ++) {
			cnt[s[i]] ++;
		}
		string tag = "";
		for (auto it = cnt.begin(); it != cnt.end(); ++ it) {
			if (it -> second > 0) {
				tag += it -> first;
			}
		}
		st.insert(tag);
	}
	printf("%d\n", st.size());
	return 0;
}
