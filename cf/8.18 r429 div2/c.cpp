#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 2e5 + 10;
struct bb {
	int a, id;
} b[MAX];
bool cmp(const bb& b1, const bb& b2)
{
	return b1.a > b2.a;
}
int main()
{
	std::ios::sync_with_stdio(false);
	
	int n, a[MAX];
	cin >> n;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i ++) {
		cin >> b[i].a;
		b[i].id = i;
	}
	int ans[MAX];
	sort(b + 1, b + 1 + n, cmp);
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i ++) {
		ans[b[i].id] = a[i];
	}
	cout << ans[1];
	for (int i = 2; i <= n; i ++) {
		cout << " " << ans[i];
	}
	cout << endl;
}
