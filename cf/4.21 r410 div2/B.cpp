#include <string>
#include <cstring>
#include <iostream>
using namespace std;

int main()
{
	int n;
	string a;
	string s[55];
	string loc[55];
	int dis[55];
	while (~scanf("%d",&n)) {
		int flag = 1;
		memset(dis,0,sizeof(dis));
		for (int i = 0; i < n; i ++) {
			cin >> s[i];
		}
		a = loc[0] = s[0];
		for (int i = 1; i < a.size(); i ++) {
			a += a[0];
			a.erase(0,1);
//			cout << a.size() << endl;
//			cout << a << endl;
			loc[a.size() - i] = a;
		}
		for (int j = 1; j < n; j ++) {
			int i;
			for (i = 0; i < a.size(); i ++) {
				if (s[j] == loc[i]) {
					dis[j] = i;
//					cout << "dis[j] " << j << " " << i << endl; 
					break;
				}
			}
			if (i == a.size()) {
				flag = 0;
				break;
			}
		}
		if (flag == 0) {
			printf("-1\n");
			continue;
		}
		int sum = 0, minn = 99999999;
		for (int j = 0; j < a.size(); j ++) {
			sum = 0;
			for (int i = 0; i < n; i ++) {
				sum += dis[i];
			}
			if (sum < minn) {
				minn = sum;
			}
			for (int i = 0; i < n; i ++) {
				if (dis[i] == a.size() - 1) {
					dis[i] = 0;
				} else {
					dis[i] ++;
				}
			}
		}
		cout << minn << endl;
		
		
	}
}
