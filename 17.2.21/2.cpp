#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node {
	int id;
	int f;
	int s;
};

bool cmp(Node& a, Node& b) {
	if (a.f - a.s > b.f - b.s) return true;
	if (a.f - a.s < b.f - b.s) return false;
	if (a.s < b.s) return true;
	if (a.s > b.s) return false;
	return a.id < b.id;
}

int main()
{
	Node node[100000];
	int n;
	while (~scanf("%d",&n)) {
		for (int i = 0; i < n; i ++) {
			node[i].id = i;
			int f,s;
			scanf("%d%d",&f,&s);
			node[i].f = f;
			node[i].s = s;
		}
		sort(node,node + n,cmp);
		printf("%d",node[0].id);
		for (int i = 1; i < n; i ++) {
			printf(" %d",node[i].id);
		}
		printf("\n");
	}
	return 0;
}
