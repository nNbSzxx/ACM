#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#define ll long long 
using namespace std;
const ll MAX = 14;
vector<ll> a;

ll solve(ll id)
{
	if (a[id] == 0) return 0;
	ll all = a[id] / MAX;
	ll left = a[id] % MAX;
	vector<ll> tmp = a;
	tmp[id] = 0;
	ll start = (id + 1) % MAX;
	for (ll i = start, cnt = 0; cnt < MAX; ++ cnt, i = (i + 1) % MAX) {
		tmp[i] += all;
	}
	for (ll i = start, cnt = 0; cnt < left; ++ cnt, i = (i + 1) % MAX) {
		tmp[i] += 1;
	}
	ll ret = 0;
	for (int i = 0; i < MAX; i ++) {
		if (!(tmp[i] & 1)) {
			ret += tmp[i];
		}
	}
	return ret;
}

int main()
{
	for (int i = 0; i < MAX; i ++) {
		ll t;
		scanf("%lld", &t);
		a.push_back(t);
	}
	ll maxx = 0;
	for (int i = 0; i < MAX; i ++) {
		maxx = max(solve(i), maxx);
	}
	printf("%lld\n", maxx);
	return 0;
}
