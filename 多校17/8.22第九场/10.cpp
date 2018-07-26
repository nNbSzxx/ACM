#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 2510;
char tag[MAX], pat[MAX];
int lp, lt;

bool match(int loct, int locp);

bool matchstar(int loct, int locp)
{
    char c = pat[locp];
    //printf("%c\n", c);
    int flag = 0;
    if (c == '.') flag = 1;
    locp += 2;
    do {
        if (match(loct, locp)) {
            return true;
        }
        if (flag) {
            c = tag[loct];
            flag = 0;
        }
    } while (tag[loct] != '\0' && (tag[loct ++] == c));
    return false;
}

bool match(int loct, int locp)
{
    if (pat[locp] == '\0' && tag[loct] == '\0') {
        return true;
    } else {
        if (tag[loct] == '\0') {
            ++locp;
            while (locp < lp && pat[locp] == '*') locp += 2;
            if (locp <= lp) return false;
            else return true;
        }
        if (pat[locp] == '\0')
            return false;
    }
    if (locp + 1 < lp && pat[locp + 1] == '*') {
        return matchstar(loct, locp);
    }
    if (pat[locp] == '.') {
        return match(loct + 1, locp + 1);
    }
    if (pat[locp] == tag[loct]) {
        return match(loct + 1, locp + 1);
    }
    return false;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while (t --) {
        scanf(" %s %s", tag, pat);
        lp = strlen(pat);
        lt = strlen(tag);
        if (match(0, 0)) {
            puts("yes");
        } else {
            puts("no");
        }
    }
    return 0;
}
