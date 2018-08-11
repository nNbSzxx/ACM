#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set> 
using namespace std;
const int MAX = 1e5 + 10;
int n;
map<int, int> mp;
set<int> st;
int a[MAX];
int sum[MAX];

int main()
{
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1];
		if (st.find(a[i]) == st.end()) {
			st.insert(a[i]);
			++ sum[i];
		}
	}
	st.clear();
	long long ans = 0;
	for (int i = n; i >= 1; i --) {
		if (st.find(a[i]) == st.end()) {
			st.insert(a[i]);
			ans += sum[i - 1];
		}
	}
	printf("%lld\n", ans);
	return 0;
}
