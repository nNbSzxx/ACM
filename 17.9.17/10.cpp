#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int MAX = 1e5 + 10;
int n, a[MAX], flag[MAX];
int l[MAX], r[MAX];
int rec[MAX], rcnt, doit[MAX], dcnt, tempdoit[MAX], tcnt, vis[MAX];

void init()
{
    //cout << "aaaaaaa" << endl;
	for (int i = 2; i < n; i ++) {
		l[i] = i - 1;
		r[i] = i + 1;
	}
	r[1] = 2; l[1] = 0;
	r[n] = n + 1; l[n] = n - 1;
	return ;
}

void del(int a)
{
    if (a == 0) return ;
    if (a == 1) {
        l[r[a]] = l[a];
        return ;
    }
    if (a == n) {
        r[l[a]] = r[a];
        return ;
    }
	l[r[a]] = l[a];
	r[l[a]] = r[a];
	return ;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf("%d", &n);
        init();
        memset(vis, 0, sizeof vis);
        a[0] = -1;
        a[n + 1] = INF;
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &a[i]);
        }
        int flag = 1;
        int b = 1, e = n;
        for (int i = 0; i < n; i ++) {
            doit[i] = i + 1;
        }
        dcnt = n;
        while (flag) {
            tcnt = 0;
            rcnt = 0;
            flag = 0;
            int i = 0;
            while (i < dcnt) {
                if (a[doit[i]] > a[r[doit[i]]]) {
                    flag = 1;
                    if (!vis[doit[i]])
                        rec[rcnt ++] = doit[i];
                    if (!vis[r[doit[i]]])
                        rec[rcnt ++] = r[doit[i]];
                    vis[doit[i]] = vis[r[doit[i]]] = 1;
                    tempdoit[tcnt ++] = l[doit[i]];
                }
                i ++;
            }
            for (int ii = 0; ii < rcnt; ii ++) {
                del(rec[ii]);
                if (rec[ii] == b) {
                    b = r[rec[ii]];
                } else if (rec[ii] == e) {
                    e = l[rec[ii]];
                }
            }
            memcpy(doit, tempdoit, sizeof(int) * (tcnt + 1));
            dcnt = tcnt;
        }
        int cnt = 0;
        for (int i = b; i <= e; i = r[i]) {
            ++ cnt;
        }
        if (cnt == 0) {
            puts("0\n");
        } else {
            printf("%d\n", cnt);
            for (int i = b; i <= e; i = r[i]) {
                printf("%d ", a[i]);
            }
            puts("");
        }
    }
}
