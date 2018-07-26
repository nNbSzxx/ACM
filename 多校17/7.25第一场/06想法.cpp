#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e6 + 10;
const int mod = 1e9 + 7;
int n, m, a[MAX], b[MAX];
int suma[MAX], sumb[MAX], vis[MAX];
long long val[MAX];
long long temp[MAX];

int main()
{
	int t = 1;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i ++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < m; i ++) {
			scanf("%d", &b[i]);
		}
		memset(suma, 0, sizeof(suma));
		memset(vis, 0, sizeof(vis));
		int l, s;
		int maxa = -1 , maxb = -1;
		for (int i = 0; i < n; i ++) {
			if (!vis[a[i]]) {
				vis[a[i]] = 1;
				s = 1;
				l = a[i];
				while (!vis[a[l]]) {
					++ s;
					vis[a[l]] = 1;
					l = a[l];
				}
				maxa = max(maxa, s);
				++ suma[s];
			}
		}
		memset(sumb, 0, sizeof(sumb));
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < m; i ++) {
			if (!vis[b[i]]) {
				vis[b[i]] = 1;
				s = 1;
				l = b[i];
				while (!vis[b[l]]) {
					++ s;
					vis[b[l]] = 1;
					l = b[l];
				}
				maxb = max(maxb, s);
				++ sumb[s];
			}
		}
		memset(val, 0, sizeof(val));
		long long ans = 1;
		for (int i = 1; i <= maxb; i ++) {
			if (sumb[i]) {
				for (int j = i; j <= maxa; j += i) {
					val[j] = (val[j] + (long long)(i) * sumb[i]) % mod;  
				}
			}
		}
		/*
		cout << "val: ";
		for (int i = 1; i <= maxa; i ++) {
			cout << val[i] << " ";
		}
		cout << endl;
		*/
		for (int i = 1; i <= maxa; i ++) {
			for (int j = 1; j <= suma[i]; j ++) {
				ans = ans * val[i] % mod;
			}
		}
		cout << "Case #" << t ++ <<  ": ";
		cout << ans << endl;
		/*
		for (int i = 1; i <= maxa; i ++) {
			cout << suma[i] << " ";
		}
		cout << endl;
		for (int i = 1; i <= maxb; i ++) {
			cout << sumb[i] << " ";
		}
		cout << endl;
		*/
	}
	return 0;
}



