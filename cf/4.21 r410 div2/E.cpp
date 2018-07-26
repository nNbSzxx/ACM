#include <cstring>
#include <cstdio>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

int cur, n;
int code[500010], ori[500010];
stack<int> s;
map<int, int> m;
void dfs(int x)
{
	while (x != -1 && cur > 0) {
		ori[x] = cur --;
		if (m.count(x))
			x = m[x];
		else 
			break;
	}
}
int main()
{
	while (~scanf("%d",&n)) {
		cur = n;
		while (!s.empty()) {
			s.pop();
		}
		m.clear();
		for (int i = 1; i <= n; i ++) {
			scanf("%d",&code[i]);
			m[code[i]] = i;
			if (code[i] == -1) {
				ori[i] = cur --;
				s.push(i);
			}
		}
		while (cur > 0 && !s.empty()) {
			int now = s.top(); s.pop();
			dfs(m[now]);
		}
		printf("%d",ori[1]);
		for (int i = 2; i <= n; i ++) {
			printf(" %d",ori[i]);
		}
		printf("\n");
	}
}
