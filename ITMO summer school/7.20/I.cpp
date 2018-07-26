#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
using namespace std;
const int MAX = 50;
long long ans;
char s[MAX], a[MAX], b[MAX];
int len;

/*
void dfs(int x, int y, int l)
{
	if (l == len) {
		++ ans;
		return ;
	}
	if (x == y) {
		a[x] = s[l];
		dfs(x + 1, y, l + 1);
		b[y] = s[l];
		dfs(x, y + 1, l + 1);
	} else if (x > y) {
		if (a[y] == s[l]) {
			b[y] = s[l];
			dfs(x, y + 1, l + 1);
		}
		if (x < len / 2) {
			a[x] = s[l];
			dfs(x + 1, y, l + 1);
		}
	} else if (y > x) {
		if (b[x] == s[l]) {
			a[x] = s[l];
			dfs(x + 1, y, l + 1);
		}
		if (y < len / 2) {
			b[y] = s[l];
			dfs(x, y + 1, l + 1);
		}
	}
}
*/

struct node{
	string a, b;
	node (const string& aa, const string& bb) : 
		a(aa), b(bb) {}
	bool operator== (const node& rhs) const {
		return (a == rhs.a && b == rhs.b);
	}
	bool operator< (const node& rhs) const {
		return (a < rhs.a || a == rhs.a && b < rhs.b);
	}
};
map<node, int> m;
void dfs(int x, int y, int l)
{
	if (l == len / 2) {
		a[x] = b[y] = '\0';
		if (strlen(a) > strlen(b)) {
			m[node(a, b)] ++;
		} else {
			m[node(b, a)] ++;
		}
		return ;
	}
	if (x == y) {
		a[x] = s[l];
		dfs(x + 1, y, l + 1);
		b[y] = s[l];
		dfs(x, y + 1, l + 1);
	} else if (x > y) {
		if (a[y] == s[l]) {
			b[y] = s[l];
			dfs(x, y + 1, l + 1);
		}
		a[x] = s[l];
		dfs(x + 1, y, l + 1);
	} else if (y > x) {
		if (b[x] == s[l]) {
			a[x] = s[l];
			dfs(x + 1, y, l + 1);
		}
		b[y] = s[l];
		dfs(x, y + 1, l + 1);
	}
}
void dfs(int x, int y, int l, int cnt)
{
//	cout << x << " " << y << " " << l << endl;
	if (l == len) {
		ans += cnt;
		return ;
	}
	if (x == y) {
		a[x] = s[l];
		dfs(x + 1, y, l + 1, cnt);
		b[y] = s[l];
		dfs(x, y + 1, l + 1, cnt);
	} else if (x > y) {
		if (a[y] == s[l]) {
			b[y] = s[l];
			dfs(x, y + 1, l + 1, cnt);
		}
		if (x < len / 2) {
			a[x] = s[l];
			dfs(x + 1, y, l + 1, cnt);
		}
	} else if (y > x) {
		if (b[x] == s[l]) {
			a[x] = s[l];
			dfs(x + 1, y, l + 1, cnt);
		}
		if (y < len / 2) {
			b[y] = s[l];
			dfs(x, y + 1, l + 1, cnt);
		}
	}
}
void dfs(const string& s1, const string& s2, int cnt)
{
	strcpy(a, s1.data());
	strcpy(b, s2.data());
	dfs(s1.size(), s2.size(), len / 2 , cnt);
}
int main()
{
	scanf("%s", s);
	len = strlen(s);
	dfs(0, 0, 0);
	for (auto it = m.begin(); it != m.end(); it ++) {
//		cout << it -> first.a << " " << it -> second << endl;
		dfs(it -> first.a, it -> first.b, it -> second);
	}
	printf("%lld\n", ans);
	return 0;
}
