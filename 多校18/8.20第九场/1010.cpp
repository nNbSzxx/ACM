#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9 + 5;

int n, m;
int a[10], b[10];

int minn(int *arr, int &id)
{
    int mmin = INT_MAX;
    for (int i = 3; i; --i)
        if (arr[i] < mmin) {
            mmin = arr[i];
            id = i;
        }
    return mmin;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
            a[i] = a[i] - i + 3;
        }
        for (int i = n + 1; i <= 3; i ++) {
            a[i] = INF;
        }
        for (int i = 1; i <= m; i ++) {
            scanf("%d", &b[i]);
            b[i] = b[i] - i + 3;
        }
        for (int i = m + 1; i <= 3; i ++) {
            b[i] = INF;
        }

        int ida, idb;
        int mina = minn(a, ida);
        int minb = minn(b, idb);

        if (mina < minb) {
            puts("1");
        } else if (mina > minb) {
            puts("-1");
        } else {
            if (ida == 1 && idb == 1) {
                int tmina = min(a[2], a[3]);
                int tminb = min(b[2], b[3]);
                if (tmina < tminb) {
                    puts("1");
                } else if (tmina > tminb) {
                    puts("-1");
                } else {
                    int tmaxa = max(a[2], a[3]);
                    int tmaxb = max(b[2], b[3]);
                    if (tmaxa < tmaxb) {
                        puts("1");
                    } else if (tmaxa > tmaxb) {
                        puts("-1");
                    } else {
                        puts("0");
                    }
                }
            } else if (ida == 1 && idb >= 2){
                if (m == 3) {
                    puts("-1");
                } else {
                    int tmina = min(a[2], a[3]);
                    int tminb = b[1];
                    if (tmina < tminb) {
                        puts("1");
                    } else if (tmina > tminb) {
                        puts("-1");
                    } else {
                        if (n == 3) {
                            puts("1");
                        } else if (n == 2) {
                            puts("0");
                        } else {
                            puts("-1");
                        }
                    }
                }
            } else if (ida >= 2 && idb == 1) {
                if (n == 3) {
                    puts("1");
                } else {
                    int tminb = min(b[2], b[3]);
                    int tmina = a[1];
                    if (tmina < tminb) {
                        puts("1");
                    } else if (tmina > tminb) {
                        puts("-1");
                    } else {
                        if (m == 3) {
                            puts("-1");
                        } else if (m == 2) {
                            puts("0");
                        } else {
                            puts("1");
                        }
                    }
                }
            } else {
                int othera = ((ida == 2) ? 3 : 2);
                int otherb = ((idb == 2) ? 3 : 2);
                if (a[othera] < b[otherb]) {
                    puts("1");
                } else if (a[othera] > b[otherb]) {
                    puts("-1");
                } else {
                    if (a[1] < b[1]) {
                        puts("1");
                    } else if (a[1] > b[1]) {
                        puts("-1");
                    } else {
                        puts("0");
                    }
                }
            }
        }

    }
    return 0;
}
