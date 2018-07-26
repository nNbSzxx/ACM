#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 5;
int n1,m1,n2,m2,len1,len2;
int father[MAX];

struct Node {
	int sum, iscircle;
	bool operator!= (const Node &rhs) {
		return (sum != rhs.sum || iscircle != rhs.iscircle);
	};
} node[MAX], arr1[MAX], arr2[MAX];

int find(int x)
{
	while (x != father[x]) {
		father[x] = father[father[x]];
		x = father[x];
	}
	return x;
}
void merge(int x, int y)
{
	x = find(x);
	y = find(y);
	if (x == y) {
		node[x].iscircle = 1;
	} else {
		father[y] = x;
		node[x].sum += node[y].sum;
	}
	return ;
}
void deal(int n, int m, Node *arr, int &len)
{
	int u, v;
	for (int i = 1; i <= n; i ++) {
		father[i] = i;
		node[i].sum = 1;
		node[i].iscircle = 0;
	}
	for (int i = 1; i <= m; i ++) {
		scanf("%d%d",&u,&v);
		merge(u, v);
	}
	for (int i = 1; i <= n; i ++) {
		if (find(i) == i) {
			arr[len].sum = node[i].sum;
			arr[len ++].iscircle = node[i].iscircle;
		}
	}
}
bool cmp(Node &e1, Node &e2)
{
	if(e1.sum != e2.sum) return e1.sum > e2.sum;
	else return e1.iscircle > e2.iscircle;
}
bool judge()
{
	if (len1 != len2) {
		return false;
	}
	sort(arr1, arr1 + len1, cmp);
	sort(arr2, arr2 + len2, cmp);
	for (int i = 0; i < len1; i ++) {
		if (arr1[i] != arr2[i]) {
			return false;
		}
	}
	return true;
}
int main()
{
	int t, tc = 1;
	scanf("%d",&t);
	while (t --) {
		len1 = len2 = 0;
		printf("Case #%d: ", tc ++);
		scanf("%d%d",&n1,&m1);
		deal(n1, m1, arr1, len1);
		
		scanf("%d%d",&n2,&m2); 
		if (n1 != n2 || m1 != m2) {
			puts("NO");
			int u, v;
			for (int i = 1; i <= m2; i ++) {
				scanf("%d%d",&u,&v);
			}
			continue;
		}
		deal(n2, m2, arr2, len2);
		
		if (judge()) {
			puts("YES");
		} else {
			puts("NO");
		}
	}
	return 0;
}
