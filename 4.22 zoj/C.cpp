#include <iostream>
#include <cstdio>
#include <bitset>
#include <string>
#include <cstring>
#include <map>
using namespace std;
int n,q,c,t;
bitset<22> bs[210];
bitset<22> pattern;
string name[210], s;
map<string, int> m;

int main()
{
	scanf("%d",&t);
	while (t --) {
		scanf("%d%d%d",&n,&q,&c);
		memset(bs,0,sizeof(bs));
		for (int i = 1; i <= c; i ++) {
			cin >> name[i];
			m[name[i]] = i;
		}
		int tt;
		for (int i = 1; i <= q; i ++) {
			scanf("%d",&tt);
			for (int j = 1; j <= tt; j ++) {
				cin >> s;
				bs[m[s]][i] = 1;
			}
		}
		pattern = 0;
		int bit, cnt, loc;
		for (int i = 1; i <= n; i ++) {
			for (int j = 1; j <= q; j ++) {
				scanf("%d",&bit);
				pattern[j] = bit;
			}
			cnt = 0;
			loc = 0;
			for (int j = 1; j <= c; j ++) {
				if (pattern == bs[j]) {
					++ cnt;
					loc = j;
				}
			}
			if (cnt != 1) {
				puts("Let's go to the library!!");
			} else {
				cout << name[loc] << endl;
			}
		}
	}
	return 0;
}
