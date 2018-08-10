#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>
using namespace std;
const int MAX = 1010; 

set<int> st;

int main()
{
	int n;
	scanf("%d", &n);
	int a[MAX];
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
	}
	vector<int> ans;
	for (int i = n; i >= 1; i --) {
		if (st.find(a[i]) == st.end()) {
			st.insert(a[i]);
			ans.push_back(a[i]);
		}
	}
	printf("%d\n", ans.size());
	for (int i = ans.size() - 1; i >= 0; i --) {
		printf("%d ", ans[i]);
	}
	return 0;
}
