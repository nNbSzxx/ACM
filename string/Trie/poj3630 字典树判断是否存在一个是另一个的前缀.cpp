#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1e4 + 10;
const int MAXC = 12;
const int MAXL = 12;

struct Trie {
    int sum;
    int nt[MAXC];
} trie[MAX * MAXL];
int cnt, n;
bool ans;

void insert(char *s, int len)
{
    int id = 0;
    for (int i = 0; i < len; i ++) {
        int x = s[i] - '0';
        if (trie[id].nt[x] == 0) {
            trie[id].nt[x] = ++ cnt;
            trie[cnt].sum = 0;
            memset(trie[cnt].nt, 0, sizeof trie[cnt].nt);
        }
        id = trie[id].nt[x];
        if (i == len - 1) {
            trie[id].sum ++;
        }
    }
}

void dfs(int x, int hasFa)
{
    if (hasFa && trie[x].sum) {
        ans = false;
        return;
    }
    if (trie[x].sum) {
        hasFa = 1;
    }
    for (int i = 0; i < 10; i ++) {
        int id = trie[x].nt[i];
        if (id != 0) {
            dfs(id, hasFa);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        cnt = 0;
        memset(trie[0].nt, 0, sizeof trie[0].nt);
        scanf("%d", &n);
        char s[MAXL];
        for (int i = 1; i <= n; i ++) {
            scanf(" %s", s);
            insert(s, strlen(s));
        }
        ans = true;
        dfs(0, 0);
        if (ans) {
            puts("YES");
        } else {
            puts("NO");
        }
    }
    return 0;
}
