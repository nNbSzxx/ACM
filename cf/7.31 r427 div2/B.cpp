#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main()
{
	long long k;
	string s;
	cin >> k >> s;
	long long sum  =0 ;
	int vis[15];
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < s.size(); i ++) {
		sum += s[i] - '0';
		vis[s[i] - '0'] ++;
	}
//	int leading = s[0] - '0' - 1;
	
	if (sum >= k) {
		cout << 0 << endl;
		return 0;
	}
	int times = 0, flag = 0;
	for (int i = 0; i <= 9; i ++) {
		while (vis[i] --) {
			sum += 9 - i;
			++ times;
			if (sum >= k) {
				flag = 1;
				break;
			}
		}
		if (flag) break;
	}
	cout << times << endl;
	return 0;	
} 
