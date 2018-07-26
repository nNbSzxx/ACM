#include <bits/stdc++.h>
const int MAX = 1e6 + 10;
int n, a[MAX * 2], maxx;

inline char nc() {
    static char buf[100000], *p1 = buf, *p2 = buf;
    return p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 100000, stdin), p1 == p2) ? '@' : *p1++;
}
int over;
inline int _read() {
    char ch = nc();
    int s = 0;
    while(!(ch >= '0' && ch <= '9')) {
        ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    while(ch >= '0' && ch <= '9') {
        s = s * 10 + ch - 48, ch = nc();
        if(ch == '@') { over = 1; break; }
    }
    return s;
}

int main()
{
    //freopen("1012.in", "r", stdin);
    while (1) {
        n = _read();
        if (over) break;
        for (int i = 1; i <= n; i ++) {
            a[i] = _read();
            a[i + n] = a[i];
        }
        int t;
        for (int i = 1; i <= n; i ++) {
            t = _read();
            a[i] -= t;
            a[i + n] -= t;
        }
        int curloc = 1, maxloc = 1;
        maxx = 0;
        t = 0;
        for (int i = 1; i <= 2 * n; i ++) {
            t += a[i];
            if (t > maxx) {
                maxx = t;
                maxloc = curloc;
            }
            if (t < 0) {
                t = 0;
                if (i >= n) break;
                curloc = i + 1;
            }
        }
        printf("%d\n", maxloc - 1);
    }
}
