#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX = 5e5 + 10;
int bit[32];
int a[MAX], n;
long long ans, cnt[32][2];
struct trie {
    trie* nt[2];
    int cnt, expt;
    trie () {
        memset(nt, 0, sizeof nt);
        cnt = expt = 0;
    }
};
void cal(trie* tmp,long long c)
{
    ans += 1LL * tmp->cnt * (tmp->cnt - 1) / 2;
    ans += 1LL * (c - tmp->cnt) * tmp->cnt - tmp->expt;
}

void add(trie* t, int x)
{
    int now;
    for (int i = 1; i <= 31; i ++) {
        now = !!(x & bit[31 - i]);
        cnt[i][now] ++;
        if (t->nt[now] == NULL) {
            t->nt[now] = new trie;
        }
        if (t->nt[now ^ 1] != NULL) {
            cal(t->nt[now ^ 1], cnt[i][now ^ 1]);
        }
        t = t->nt[now];
        t->cnt ++;
        t->expt += cnt[i][now] - t->cnt;
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    bit[0] = 1;
    for (int i = 1; i <= 31; i ++) {
        bit[i] = bit[i - 1] << 1;
    }
    while (T --) {
        memset(cnt, 0, sizeof cnt);
        trie t;
        ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            add(&t, a[i]);
        }
        printf("%lld\n", ans);
    }

    return 0;
}
