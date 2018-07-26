#include <vector>
#include <iostream>
#include <cstdio>
#include <queue>
#include <map>
using namespace std;
queue<string> q;
map<string, int> m;

int main()
{
	int t,n;
	string s1,s2;
	scanf("%d",&t);
	while (t --) {
		while (!q.empty()) {
			q.pop();
		}
		m.clear();
		int cnt = 0;
		scanf("%d",&n);
		for (int i = 1; i <= n; i ++)
		{
			cin >> s1 >> s2;
			if (s1 == "in") {
				q.push(s2);
			} else {
				while (m[q.front()] ) {
					q.pop();
				}
				if (q.front() == s2) {
					++ cnt;
					q.pop();
				} else {
					m[s2] = 1;
				}
			}	
		}	
		cout << cnt << endl;
	}
}
