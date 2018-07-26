#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
char tag[MAX], tp[55];
struct node {
	node *nt[26];
	node *fail;
	int sum;
} *root;
int ans, n;

void add(char *s, int len)
{
	node *p = root;
	for (int i = 0; i < len; i ++) {
		int x = s[i] - 'a';
		if (p -> nt[x] == NULL) {
			node *temp = new node;
			for (int i = 0; i < 26; i ++) {
				temp -> nt[i] = 0;
			}
			temp -> sum = 0;
			temp -> fail = root;
			p -> nt[x] = temp;
		}
		p = p -> nt[x];
		if (i == len - 1) {
			p -> sum ++;
		}
	}
	return ;
}

node *getfail(node *p, int x)
{
	if (p -> nt[x] != NULL) return p -> nt[x];
	if (p == root) return root;
	return getfail(p -> fail, x);
}

void build(void)
{
	queue<node *> q;
	q.push(root);
	node *now;
	while (!q.empty()) {
		now = q.front(); q.pop();
		for (int i = 0; i < 26; i ++) {
			if (now -> nt[i] != NULL) {
				q.push(now -> nt[i]);
				if (now == root) {
					now -> nt[i] -> fail = root;
				} else {
					now -> nt[i] -> fail = getfail(now -> fail, i);
				}
			}
		}
	}
	return ;
}

void solve()
{
	int len = strlen(tag);
	node *p = root;
	for (int i = 0; i < len; i ++) {
		int x = tag[i] - 'a';
		while (p -> nt[x] == NULL && p != root) p = p -> fail;
		p = (p -> nt[x] == NULL) ? root : (p -> nt[x]);
		node *temp = p;
		while (temp != root) {
			ans += temp -> sum;
			temp -> sum = 0;
			temp = temp -> fail;
		}
	}
	return ;
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t --) {
		ans = 0;
		root = new node;
		for (int i = 0; i < 26; i ++) {
			root -> nt[i] = 0;
		}
		root -> sum = 0;
		root -> fail = root;
		
		scanf("%d", &n);
		for (int i = 1; i <= n; i ++) {
			scanf(" %s", tp);
			add(tp, strlen(tp));
		}
		scanf(" %s", tag);
		build(); 
		solve();
		printf("%d\n", ans);
	}
} 
