#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
using namespace std;
const int MAX = 110;

int a[MAX];
int n, d;
set<int> st;

bool check(int x, int id)
{
	for (int i = 1; i <= n; i ++) {
		if (i == id) {
			continue;
		}
		if (abs(a[i] - x) < d) {
			return false;
		}
	}
	return true;
}

int main()
{
	scanf("%d%d", &n, &d);
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	} 
	for (int i = 1; i <= n; i ++) {
		int x = a[i] + d;
		if (check(x, i)) {
			st.insert(x);
		}
		x = a[i] - d;
		if (check(x, i)) {
			st.insert(x);
		}
	}
	printf("%d\n", st.size());
	return 0;
}
