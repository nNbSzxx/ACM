#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
int n,k;
char s[2][200010];

struct pos {
	int cliff;
	int loc;
	int t;
} p;
queue<pos> q;
inline pos movee(pos& x, int i)
{
	pos t;
	if (i == 1) {
		t.cliff = x.cliff;t.loc = x.loc+1; t.t=x.t +1;return t;
	}
	if (i == 2) {
		t.cliff = x.cliff;t.loc = x.loc-1; t.t=x.t +1;return t;
	}
	if (i == 3) {
		if (x.cliff ) {
			t.cliff = 0;
		} else t.cliff = 1;
		t.loc =x.loc + k;
		t.t = x.t +1;
		return t;
	}
}
inline bool isDied(pos& x, int t)
{
	return x.loc <= t;
}
bool bfs()
{
	pos x = {0,1,0};
	q.push(x);
	s[0][1] = 'X';
	while (!q.empty()) {
		pos now = q.front(); q.pop();
		for (int i = 1; i <= 3; i ++) {
			pos x = movee(now,i);
			if (x.loc > n) return true;
			if (s[x.cliff][x.loc] == '-' && !isDied(x, x.t)) {
				q.push(x);
				s[x.cliff][x.loc] = 'X';
			}
		}
	}
	return false;
}

int main()
{

	scanf("%d%d",&n,&k);
	scanf(" %s %s", s[0] + 1, s[1] + 1);
	if (bfs()) {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
}
