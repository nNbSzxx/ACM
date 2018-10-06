#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1e5 + 10;

char s[MAX], p[MAX];
int nt[MAX];

int main()
{
    int tc = 1;
    while (~scanf(" %s", s)) {
        printf("Case %d: ", tc ++);

        int n = strlen(s);
        int m = 1;
        p[0] = s[0];
        nt[0] = -1;
        nt[1] = 0;

        int i = 0, j = 0, last = 0, lastjj = 0;
        while (i < n) {
            if (s[i] != p[j]) {
                j = nt[j];
            } else {
                ++ i; ++ j;
                if (j == m) {
                    last = i - 1;
                    j = nt[j];
                }
            }

            if (j == -1) {
                int ii = m;
                int jj = lastjj;
                for (int k = last + 1; k <= i; k ++) {
                    p[m ++] = s[k];
                }

                while (ii < m) {
                    if (jj == -1 || p[ii] == p[jj]) {
                        nt[++ ii] = ++ jj;
                        lastjj = jj;
                    } else {
                        jj = nt[jj];
                    }
                }
                last = i;
                ++ i;
                ++ j;
            }
        }
        //printf("%d %d\n", m, last);
        //printf("%s\n", p);
        printf("%d\n", m + (n - last - 1));
    }

    return 0;
}
