#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;
int n, m;
int a[MAX];
int dp[MAX];
int st[MAX][20], id[MAX][20];
vector<int> seq, seqid;

// return the index of max number
int query(int l, int r)
{
	int k = 0;
	while ((1 << (k + 1)) <= (r - l + 1)) {
		++ k;
	}
	if (st[l][k] >= st[r - (1 << k) + 1][k]) {
		return id[l][k];
	} else {
		return id[r - (1 << k) + 1][k];
	}
}

int bins(int ll, int rr, int p)
{
	int l = ll, r = rr, mid, ret = -1;
	while (l <= r) {
		mid = (l + r) >> 1;
		int idx = query(ll, mid);
		if (a[idx] > p) {
			r = mid - 1;
			ret = idx;
		} else {
			l = mid + 1;
		}
	}
	return ret;
}

void init()
{
	seq.clear();
	seqid.clear();
	int last = a[1];
	seq.push_back(a[1]);
	seqid.push_back(1);
	for (int i = 2; i <= n; i ++) {
		if (a[i] > last) {
			last = a[i];
			seq.push_back(a[i]);
			seqid.push_back(i);
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		st[i][0] = a[i];
		id[i][0] = i;
	}
	for (int i = 1; i <= 20; i ++) {
		for (int j = 1; j + (1 << i) <= n + 1; j ++) {
			if (st[j][i - 1] >= st[j + (1 << (i - 1))][i - 1]) {
				st[j][i] = st[j][i - 1];
				id[j][i] = id[j][i - 1];
			} else {
				st[j][i] = st[j + (1 << (i - 1))][i - 1];
				id[j][i] = id[j + (1 << (i - 1))][i - 1];
			}
		}
	}
	
	dp[n] = 1;
	for (int i = n - 1; i >= 1; i --) {
		int idx = bins(i + 1, n, a[i]);
		if (idx == -1) {
			dp[i] = 1;
		} else {
			dp[i] = dp[idx] + 1;
		}
	}
}

int main()
{
//	freopen("j.in", "r", stdin);
//	freopen("1010.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t --) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i ++) {
			scanf("%d", &a[i]);
		}
		init();
		while (m --) {
			int p, q;
			scanf("%d%d", &p, &q);
			int idx = lower_bound(seqid.begin(), seqid.end(), p) - seqid.begin();
			int ans;
			if (p == 1 || (q > seq[idx - 1])) {
				int ntid = bins(p + 1, n, q);
				if (ntid != -1)
					ans = idx + dp[ntid] + 1;
				else
					ans = idx + 1;
			} else if (seqid.size() != idx && p == seqid[idx]) {
//				int tmp = a[p];
//				a[p] = q;
				int ntid = bins(p + 1, n, seq[idx - 1]);
				if (ntid != -1)
					ans = idx + dp[ntid];
				else
					ans = idx;
//				a[p] = tmp;
			} else {
				ans = dp[1];
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}



