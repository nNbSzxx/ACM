#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX = 50005;
struct Tree {
	int begin;
	int end;
	int sum;
};
Tree tree[MAX * 4]; 

void update(int parent)
{
	if (tree[parent].begin == tree[parent].end) return;
	tree[parent].sum = tree[parent * 2].sum + tree[parent * 2 + 1].sum;
	return ;
}

void createTree(int parent, int begin, int end)
{
	tree[parent].begin = begin;
	tree[parent].end = end;
	if (begin == end) {
		scanf("%d",&tree[parent].sum);
		return;
	}
	int mid = (begin + end) / 2;
	createTree(2 * parent, begin, mid);
	createTree(2 * parent + 1, mid + 1, end);
	update(parent);
	return ;
}

void modify(int x, int pos, int v)
{
	if (tree[x].begin == tree[x].end) {
		tree[x].sum += v;
		return ;
	} 
	int mid = (tree[x].begin + tree[x].end) / 2;
	if (pos > mid) {
		modify(x * 2 + 1, pos, v);
	} else {
		modify(x * 2, pos, v);
	}
	update(x);
	return ;
}

int query(int x, int begin, int end)
{
	if (begin <= tree[x].begin && end >= tree[x].end) {
		return tree[x].sum;
	}
	int mid = (tree[x].begin + tree[x].end) / 2;
	int ret = 0;
	if (begin <= mid) ret += query(x * 2, begin, end);
	if (end > mid) ret += query(x * 2 + 1, begin, end);
	return ret;
}

int main(int argc, char const *argv[])
{
	int n,t;
	int tc = 1;
	scanf("%d",&t);
	while (t --)
	{
		printf("Case %d:\n",tc ++);
		memset(tree,0,sizeof(tree));
		scanf("%d",&n);
		createTree(1,1,n);
		char s[15];
		while (scanf("%s",s), s[0] != 'E') {
			int a,b;
			scanf("%d%d",&a,&b);
			if (s[0] == 'Q') {
				printf("%d\n",query(1,a,b));
			}
			if (s[0] == 'A') {
				modify(1,a,b);
			}
			if (s[0] == 'S') {
				modify(1,a,-b);
			}
		}
	}
	return 0;
}
