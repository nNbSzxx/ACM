#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e5 + 10;
vector<int> v[MAX];
int main()
{
	int n, k, m;
	scanf("%d%d%d", &n ,&k, &m);
	
	int t, flag = -1;
	for (int i = 1; i <= n; i ++) {
		scanf("%d", &t);
		v[t % m].push_back(t);
		if (v[t % m].size() >= k) {
			flag = t % m;
		}
	}
	if (flag == -1) {
		puts("No");
	}
	else {
		puts("Yes");
		for (int i = 0; i < k; i ++) {
			printf("%d ", v[flag][i]);
		}
	}
}
