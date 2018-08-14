#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;
const int MAX = 1e6 + 10;

int vis[MAX];
int ans[MAX];
int n, m, minn;

struct node {
	int value;
	int curid;
	node() {}
	node(int vv, int cc): value(vv), curid(cc) {}
	bool operator< (const node& rhs) const {
		return curid < (rhs.curid);
	}
} nd[MAX];

bool cmp(const node& n1, const node& n2)
{
	return n1.curid < n2.curid;
}

tree<node, null_type, less<node>, rb_tree_tag, tree_order_statistics_node_update> rbt;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i ++) {
		nd[i].value = nd[i].curid = i;
		rbt.insert(nd[i]);
	}
	int flag = true;
	minn = 0;
	for (int i = 1; i <= m; i ++) {
		int u, v;
		scanf("%d%d", &u, &v);
		if (!flag) {
			continue;
		}
		auto it = rbt.find_by_order(v - 1);
		if (vis[it -> value] && ans[it -> value] != u) {
			flag = false;
			continue;
		}
		//printf("%d %d\n", it -> value, it -> curid);
		vis[u] = 1;
		ans[it -> value] = u;
		rbt.insert(node(it -> value, minn --));
		rbt.erase(it);
	}
	if (!flag) {
		puts("-1");
		return 0;
	}
	int id = 1;
	for (int i = 1; i <= n; i ++) {
		if (!ans[i]) {
			while (vis[id]) {
				++ id;
			}
			//printf("id i: %d %d\n", id, i);
			ans[i] = id;
			vis[id] = 1;
		}
		printf("%d ", ans[i]);
	}
	puts("");
	return 0;
}
