#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

int main()
{
	int n;
	queue<int> q;
	while (~scanf("%d",&n)) {
		string s;
		int cnt = 0;
		cin >> s;
		int len = 0;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == 'B') {
				len ++;
			} else {
				if (len != 0) {
					cnt ++;
					q.push(len);
					len = 0;
				}
			}
		}
		if (len != 0) {
			cnt ++;
			q.push(len);
		}
		printf("%d\n",cnt);
		if (!q.empty()) {
			int temp = q.front();
			q.pop();
			printf("%d",temp);
		}
		while (!q.empty()){
			printf(" %d",q.front());
			q.pop();
		}
		printf("\n");
	}
}
