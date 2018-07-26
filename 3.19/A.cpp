#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
using namespace std;
const int MAX = 105;
map<string, string> father;
set<string> group;
//inline void union(int ch, int f)
//{
//	int yy = father[y];
//	father[ch] = yy;
//}

inline string find(string x)
{
	while (x != father[x]) {
		x = father[x];
	}
	return x;
}

//inline void correct(int x, int fx)
//{
//	father[x] = fx;
//}

int main()
{
	int n;
	while (~scanf("%d",&n), n) {	
		string s, temp, first;
		char c;
		
		for (int i = 1; i <= n; i ++) {
			getchar();
			while ((c = getchar()) != ':') 
				s += c;
			if (i == 1) {
				first = s;
			}
			group.insert(s);
			if (!father.count(s)) {
				father.insert(map<string, string>::value_type(s,s));
			}
			while ((c=getchar()) != '.') {
				if (c != ',')
					temp += c;
				else {
					father[temp] = s;
					temp.clear();
				}					
			}
			father[temp] = s;
			temp.clear();
			s.clear();
		}
		int ans = 0;
		for (auto it = father.begin(); it != father.end(); it ++) {
			cout << "key " << it->first << " " <<"value "<< it->second << endl;
		}
		for (auto it = group.begin(); it != group.end(); it ++) {
			cout  << *it << endl;
		}
		for (auto it = father.begin(); it != father.end(); it ++) {
			if (find(it->second) == first && ! group.count(it->first)) {
				ans ++;
			}
		}
		printf("%d\n",ans);
		group.clear();
		father.clear();
	}
	return 0;
} 
