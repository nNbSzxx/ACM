#include <bits/stdc++.h>
using namespace std;
const int MAX = 3e5 * 31 + 10;
// num记录从根到当前节点是多少个单词的前缀，本题只含01 
int trie[MAX][2];
int n, mess[MAX], cnt, sum[MAX];

void insert(int x)
{
	int root = 0;
	for (int i = 0; i < 31; i ++) {
		int id = (x & (1 << (30 - i))) >> (30 - i);
		assert(id == 0 || id == 1);
		if (!trie[root][id]) {
			trie[root][id] = ++ cnt;
		}
		root = trie[root][id];
		sum[root] += 1;
	}
}

int greedySearch(int x)
{
	int root = 0;
	int mask = x;
	for (int i = 0; i < 31; i ++) {
		int id = (x & (1 << (30 - i))) >> (30 - i);
		assert(id == 0 || id == 1);
		if (!trie[root][id] || sum[trie[root][id]] == 0) {
			root = trie[root][id ^ 1];
			mask = mask ^ (1 << (30 - i));
		} else {
			root = trie[root][id];
		}
		-- sum[root];
	}
	
	return x ^ mask;
}

int main()
{
	// 初始化字典树 
	cnt = 0;
	memset(trie, 0, sizeof trie);
	memset(sum, 0, sizeof sum);
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &mess[i]);
	}
	int t;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		insert(t);
	}
	for (int i = 1; i <= n; i ++) {
		printf("%d ", greedySearch(mess[i]));
	}
	return 0;
}
