#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

bool read(int &x){
	char ch = getchar();
	x = 0;
	for (; ch < '0' || ch > '9'; ch = getchar()) {
		if (ch == EOF) {
			return false;
		}
	}
	for (; ch >='0' && ch <= '9'; ch = getchar()) x = x * 10 + ch - '0';
	return true;
}

int n, q, cur;
const int MAX = 4e5 + 10;

struct lst {
	deque<int> q;
	deque<int> id;
} l[MAX << 1];
int rev[MAX], idmap[MAX], num[MAX];

void init()
{
	/*
	for (int i = 1; i < (MAX << 1); i ++) {
		l[i].q.clear();
		l[i].id.clear();
	}
	*/
	memset(rev, 0, sizeof rev);
	memset(idmap, 0, sizeof idmap);
	cur = 1;
}

void insert(int u, int w, int v)
{
	int no = u;
	if (no == 0) {
		no = idmap[u] = cur ++;
		l[no].id.clear();
		l[no].q.clear();
		l[no].id.push_back(no);
		num[no] = rev[no] = 0;
	}
	if (l[no].id.size() == 1) {
		if ((w ^ rev[no]) == 0) {
			l[no].q.push_front(v);
		} else {
			l[no].q.push_back(v);
		}
		++ num[no];
		return ;
	}
	if ((w ^ re) == 0) {
		insert(l[no].id.front(), w, v);
		++ num[no];
	} else {
		insert(l[no].id.back(), w, v);
		++ num[no];
	}
	return ;
}

int del(int u, int w)
{
	-- num[u];
	int ret;
	if (l[u].id.size() == 1) {
		if ((w ^ rev[u]) == 0) {
			ret = l[u].q.front();
			l[u].q.pop_front();
		} else {
			ret = l[u].q.back();
			l[u].q.pop_back();
		}
		return ret;
	}
	if ((w ^ rev[u]) == 0) {
		int id = l[u].id.front()
		ret = del(l[u].id.front(), w);
	
		if (num[l[u].id.front()] == 0) {
			l[u].id.pop_front();
			idmap[l[u]]
		}
	} else {
		ret = del(l[u].id.back(), w);
		if (num[l[u].id.back()] == 0) {
			l[u].id.pop_back();
		}
	}
	return ret;
}

void cat(int u, int v, int w)
{
	if ()
	if (w) {
		rev[v] ^= 1;
	}
}

int main()
{
	while (read(n)) {
		init();
		read(q);
		int m, u, w, v;
		while (q --) {
			read(m);
			if (m == 1) {
				read(u);
				read(w);
				read(v);
				insert(idmap[u], w, v);
			} else if (m == 2) {
				read(u);
				read(w);
				if (idmap[u] == 0) {
					puts("0");
				} else 
					printf("%d\n", del(idmap[u], w));
			} else {
				read(u);
				read(v);
				read(w);
				cat(u, v, w);
			}
		}
	}
	return 0;
}







