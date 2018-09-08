#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <vector>
using namespace std;
const int MAXN = 260;
const int MAXM = 1e5 + 10;
const int MAXD = 2e5 + 10;
const int NC = 300;


struct dict {
    int nt[2];
    int ascii;
} tree[MAXN * 10];
int cntd;
int m, n;
char data[MAXD];
int bin[MAXD * 4];
int process[MAXD * 4], cntp;
vector<int> ans;

inline int toInt(char c)
{
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else {
        return c - 'A' + 10;
    }
}

void insert(int a, char s[15])
{
    int len = strlen(s);
    //printf("%d\n", len);
    int cur = 1;
    for (int i = 0; i < len; i ++) {
        int id = s[i] - '0';
        if (tree[cur].nt[id] == 0) {
            ++ cntd;
            tree[cur].nt[id] = cntd;
            tree[cntd].nt[0] = tree[cntd].nt[1] = 0;
            tree[cntd].ascii = NC;
        }
        cur = tree[cur].nt[id];
        if (i == len - 1) {
            tree[cur].ascii = a;
        } else {
            tree[cur].ascii = NC;
        }
    }
}

void find()
{
    int curt = 1;
    int curp = 0;
    for (int i = 0; i < cntp; i ++) {
        int id = process[i];
        curt = tree[curt].nt[id];
        if (tree[curt].ascii != NC) {
            ans.push_back(tree[curt].ascii);
            curt = 1;
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        cntd = 1;
        tree[1].nt[0] = 0;
        tree[1].nt[1] = 0;
        tree[1].ascii = NC;

        scanf("%d%d", &m, &n);
        for (int i = 1; i <= n; i ++) {
            int a;
            char s[15];
            scanf("%d %s", &a, s);
            //printf("%d %s\n", a, s);
            insert(a, s);
        }

        scanf(" %s", data);
        int lenh = strlen(data);
        int lenb = lenh * 4;
        for (int i = 0; i < lenh; i ++) {
            char c = data[i];
            int num = toInt(c);
            for (int j = 0; j < 4; j ++) {
                bin[i * 4 + j] = ( (num & (1 << (3 - j))) != 0);
            }
        }
        /*
        for (int i = 0; i < lenb; i ++) {
            printf("%d", bin[i]);
        }
        puts("");
        */
        cntp = 0;
        for (int i = 0; i < lenb; i += 9) {
            if (i + 8 > lenb - 1) {
                break;
            }
            int x = 0;
            for (int j = i; j <= i + 8; j ++) {
                x ^= bin[j];
            }
            if (x) {
                for (int j = i; j < i + 8; j ++) {
                    process[cntp] = bin[j];
                    ++ cntp;
                }
            }
        }
        ans.clear();
        find();
        for (int i = 0; i < m; i ++) {
            printf("%c", char(ans[i]));
        }
        puts("");
    }
    return 0;
}
