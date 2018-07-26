#include <bits/stdc++.h>
using namespace std;
const int MAX = 32;
int b[MAX], a[1000100];
int n, q, andd, orr, xorr;

int main()
{
    int n, q;
    while (~scanf("%d%d", &n, &q)) {
        andd = 0xffffffff, orr = 0, xorr = 0;
        memset(b, 0, sizeof b);
        int t;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &t);
            a[i] = t;
            andd &= t;
            orr |= t;
            xorr ^= t;
            for (int j = 0; t; j ++) {
                b[j] += (t % 2);
                t >>= 1;
            }
        }
        //cout << b[0] << endl << endl;
        while (q --) {
            int id;
            scanf("%d", &id);
            int ta = andd, to = orr, tx = xorr ^ a[id];
            t = a[id];
            for (int i = 0; i <= 30; i ++) {
                if ((b[i] == n - 1) && (t % 2 == 0)) {
                    ta += (1 << i);
                }
                if ((b[i] == 1) && (t % 2 == 1)) {
                    to -= (1 << i);
                }
                t >>= 1;
            }
            printf("%d %d %d\n", ta, to, tx);
        }
    }
}
