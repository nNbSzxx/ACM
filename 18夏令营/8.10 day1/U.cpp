#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set> 
using namespace std;
int n;
map<int, int> mp;
set<int> st;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i ++) {
		int a;
		scanf("%d", &a);
		if (i == 1) {
			mp[a] = 1;
			st.insert(a);
			continue;
		}
		if (mp.count(a)) {
			
		}
	}
	return 0;
}
