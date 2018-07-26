#include <bits/stdc++.h>
using namespace std;
string p[5] = { "Danil", "Olya", "Slava", "Ann", "Nikita"};
string s;

int main()
{
	cin >> s;
	int flag = 0;
	for (int i = 0; i < 5; i ++) {
		for (int j = 0; j < s.size(); j ++) {
			int f = 1;
			for (int k = 0, kk = j; k < p[i].size() && j < s.size(); k ++, kk ++) {
				if (s[kk] != p[i][k]) {
					f = 0;
					break;
				}
			}
			flag += f;
		}
	}
	if (flag == 1) {
		puts("YES");
	} else {
		puts("NO");
	}
}
