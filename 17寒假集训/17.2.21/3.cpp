#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;

int main()
{
	string std[] = {"4","16","256","65536","4294967296"};
	string s;
	while (cin >> s) {
		if (s == "0") {
			printf("TAT\n");
			continue;
		}
		if (s == "1") {
			printf("1\n");
			continue;
		}
		if (s.size() > 10) {
			printf("TAT\n");
			continue;
		}
		if (s.size() == 10) {
			if (s < std[4]) {
				printf("5\n");
			} else {
				printf("TAT\n");
			}
			continue;
		} 
		if (s.size() >= 6 && s.size() <= 9) {
			printf("5\n");
			continue;
		}
		if (s.size() == 5) {
			if (s < std[3]) {
				printf("%d\n",4);
			} else {
				printf("%d\n",5);
			}
			continue;
		}
		if (s.size() == 4) {
			printf("%d\n",4);
			continue;
		}
		if (s.size() == 3) {
			if (s < std[2]) {
				printf("%d\n",3);
			} else {
				printf("%d\n",4);
			}
			continue;
		}
		if (s.size() == 2) {
			if (s < std[1]) {
				printf("%d\n",2);
			} else {
				printf("%d\n",3);
			}
			continue;
		}
		if (s.size() == 1) {
			if (s < std[0]) {
				printf("1\n");
			} else {
				printf("2\n");
			}
		}
	}
}
