#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	string s;
	while (t --) {
		cin >> s;
		s += "1111111111";
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == '0' || s[i] == '2' || s[i] == '4' || s[i] == '6' || s[i] == '9') {
				cout << s[i];
				continue;
			}
			if (s[i] == 'z') {
				if (s[i + 1] == 'e' && s[i + 2] == 'r' && s[i + 3] == 'o') {
					cout << 0;
					i += 3;
				}
				continue;
			}
			if (s[i] == 't') {
				if (s[i + 1] == 'w' && s[i + 2] == 'o') {
					cout << 2;
					i += 2;
				}
				continue;
			}
			if (s[i] == 'f') {
				if (s[i + 1] == 'o' && s[i + 2] == 'u' && s[i + 3] == 'r') {
					cout << 4;
					i += 3;
				}
				continue;
			}
			if (s[i] == 's') {
				if (s[i + 1] == 'i' && s[i + 2] == 'x') {
					cout << 6;
					i += 2;
				}
				continue;
			}
			if (s[i] == 'n') {
				if (s[i + 1] == 'i' && s[i + 2] == 'n' && s[ i + 3] == 'e') {
					cout << 9;
					i += 3;
				}
				continue;
			}
		}
		cout << endl;
	}
}
