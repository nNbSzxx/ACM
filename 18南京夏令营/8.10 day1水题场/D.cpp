#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <vector>
using namespace std;
const int MAX = 110;
unsigned long long a[MAX];
unsigned long long ans[MAX];
map<unsigned long long, int> cnt;
bool finda;
int n;

void dfs(int id)
{
	if (finda) return ;
	if (id == n + 1) {
		finda = true;
		return ;
	}
	unsigned long long last = ans[id - 1];
	if (last % 3 == 0 && cnt[last / 3]) {
		ans[id] = last / 3;
		cnt[last / 3] --;
		dfs(id + 1);
		cnt[last / 3] ++;
	}
	if (cnt[last * 2]) {
		ans[id] = last * 2;
		cnt[last * 2] --;
		dfs(id + 1);
		cnt[last * 2] ++;
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%llu", &a[i]);
		cnt[a[i]] ++;
	}
	finda = false;
	for (int i = 1; i <= n; i ++) {
		ans[1] = a[i];
		cnt[a[i]] --;
		dfs(2);
		cnt[a[i]] ++;
		if (finda) {
			break;
		}
	}
	for (int i = 1; i <= n; i ++) {
		printf("%llu ", ans[i]);
	}
	return 0;
}
