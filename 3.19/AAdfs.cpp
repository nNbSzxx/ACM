#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <queue>
using namespace std;
const int MAX = 105;
map<string, int> h;
set<int> group;
int path[MAX*10][MAX*10];
int cnt, ans ;
bool visit[MAX*10];
//5
//a:b,c.
//e:b,f,g,h,i.
//c:e.
//p:i.
//b:p.
void dfs(int x)
{	

	for (int i = 0; i < cnt; i ++) {
		if (path[x][i] && !visit[i]) {
			visit[i] = 1;
		
			dfs(i);
		}
	}
	if (!group.count(x)) {
		ans ++;
//		printf("dfs:%d\n",x);
	}
	return ;
}

int main()
{
	int n;
	while (~scanf("%d",&n), n) {	
		string s, temp;
		memset(path,0,sizeof(path));
		memset(visit,0,sizeof(visit));
		ans = cnt = 0;
		char c;
		for (int i = 1; i <= n; i ++) {
			getchar();
			while ((c = getchar()) != ':') 
				s += c;
		
			int fa, now;
			if (!h.count(s)) {
				h.insert(map<string, int>::value_type(s,fa = cnt ++));
			} else {
				fa = h[s];
			}
			group.insert(fa);
			while ((c=getchar()) != '.') {
				if (c != ',')
					temp += c;
				else {
					if (!h.count(temp)) {
						now = cnt;
						h.insert(map<string, int>::value_type(temp,cnt ++));
					} else {
						now = h[temp];
					}
					path[fa][now] = 1;
					temp.clear();
				}					
			}
			if (!h.count(temp)) {
				now = cnt;
				h.insert(map<string, int>::value_type(temp,cnt ++));
			} else {
				now = h[temp];
			}
			path[fa][now] = 1;
			temp.clear();
			s.clear();
		}

//		for (auto it = h.begin(); it != h.end(); it ++) {
//			cout << "key " << it->first << " " <<"value "<< it->second << endl;
//		}
//		for (int i = 0; i < cnt; i ++) {
//			for (int j = 0; j < cnt; j ++) {
//				printf("%d ",path[i][j]);
//			}
//			printf("\n");
//		}
		visit[0] = 1;
		dfs(0);
		printf("%d\n",ans);
		group.clear();
		h.clear();
	}
	return 0;
} 
