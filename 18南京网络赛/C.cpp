#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <set>
using namespace std;
const int MAXM = 2e4 + 10;
const int MAXN = 205;
multiset<int> p[MAXN];
int c[MAXM];
int cur;
int n, m;

int main()
{
    int t, tc = 1;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i ++) {
            scanf("%d", &c[i]);
            if (c[i] < 3) {
                c[i] += 13;
            }
        }
        cur = 0;
        for (int i = 0; i < n; i ++) {
            p[i].clear();
            for (int j = 0; j < 5 && cur < m; j ++, cur ++) {
                p[i].insert(c[cur]);
                //printf("insert: %d %d\n", i, c[cur]);
            }
        }
        //printf("%d\n", cur);
        int turn = 0;
        int v;
        bool newround = true;
        while (true) {
            if (newround) {
                auto it = p[turn].begin();
                v = *it;
                p[turn].erase(it);
                // win?
                //printf("%d %d\n", turn, v);
                if (p[turn].empty()) {
                    break;
                }
            }

            // find next one
            int last = turn;
            for (int i = (turn + 1) % n; i != turn; i = (i + 1) % n) {
                auto it = p[i].find(v + 1);
                if (it != p[i].end()) {
                    v = v + 1;
                    p[i].erase(it);
                    last = i;
                    // win?
                    //printf("%d %d\n", i, v);
                    if (p[i].empty()) {
                        goto A;
                    }
                    break;
                } else if (v != 15) {
                    it = p[i].find(15);
                    if (it != p[i].end()) {
                        v = 15;
                        p[i].erase(it);
                        last = i;
                        // win?
                        //printf("%d %d\n", i, v);
                        if (p[i].empty()) {
                            goto A;
                        }
                        break;
                    } else {
                        continue;
                    }
                }
            }

            // end, deliver cards
            if (last == turn || v == 15) {
                for (int i = last; cur < m; i = (i + 1) % n) {
                    p[i].insert(c[cur++]);
                    //printf("insert: %d %d\n", i, c[cur - 1]);
                    if (i == (last - 1 + n) % n) {
                        break;
                    }
                }
                newround = true;
            } else {
                newround = false;
            }
            turn = last;
        }
        A:
        printf("Case #%d:\n", tc ++);
        for (int i = 0; i < n; i ++) {
            int pena = 0;
            for (int a : p[i]) {
                if (a > 13) {
                    a -= 13;
                }
                //printf("left: %d %d\n", i, a);
                pena += a;
            }
            if (pena != 0)
                printf("%d\n", pena);
            else
                puts("Winner");
        }
    }

    return 0;
}
