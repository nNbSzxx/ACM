#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000 + 10;
const int INF = -0x3f3f3f3f;
char s[MAX];

int main()
{
    scanf("%s", s);
    int len = strlen(s), cnt = len;
    if (len == 1) {
        if ((s[0] - '0') % 3 == 0) {
            printf("%c\n", s[0]);
        } else {
            puts("-1");
        }
        return 0;
    }
    int mod = 0, t;
    int sum[3], print[MAX];
    memset(sum, 0, sizeof(sum));
    memset(print, 1, sizeof(print));
    for (int i = 0; i < len; i ++) {
        t = (s[i]- '0') % 3;
        mod += t;
        sum[t] ++;
    }
    mod %= 3;
    if (mod == 0) {
        for (int i = 0; i < len; i ++) {
            printf("%c",s[i]);
        }
        puts("");
        return 0;
    }

    if (sum[mod] > 1 || sum[mod] == 1 && (s[0] - '0') % 3 != mod) {
        for (int i = len - 1; i >= 1; i --) {
            if ((s[i] - '0') % 3 == mod) {
                print[i] = 0;
                break;
            }
        }
        for (int i = 0; i < len; i ++) {
            if (print[i])
                printf("%c",s[i]);
        }
        puts("");
        return 0;
    }

    int cnt1, cnt2;
    if (sum[mod] == 1 && (s[0] - '0') % 3 == mod) {
        cnt1 = len - 1;
        int i = 1;
        while (i < len && s[i] == '0') {
            cnt1 --;
            i ++;
        }
        if (i == len) {
            cnt1 = 1;
        }

        int del = 0, fflag = 0;
        for (int i = len - 1; i >= 0; i --) {
            if ((s[i] - '0') % 3 == 3 - mod) {
                ++ del;
                if (del == 2) break;
            }
        }
        if (del <= 1) {
            cnt2 = INF;
        } else if (del == 2){
            cnt2 = len - 2;
        }

        if (cnt1 >= cnt2) {
            int i = 1;
            print[0] = 0;
            while (i < len && s[i] == '0') {
                print[i] = 0;
                ++ i;
            }
            if (i == len) print[len - 1] = 1;
            for (int i = 0; i < len; i ++) {
                if (print[i])
                    printf("%c",s[i]);
            }
            puts("");
            return 0;
        }
        if (cnt1 < cnt2) {
            del = 0;
            for (int i = len - 1; i >= 0; i --) {
                if ((s[i] - '0') % 3 == 3 - mod) {
                    ++ del;
                    print[i] = 0;
                    if (del == 2) break;
                }
            }
            for (int i = 0; i < len; i ++) {
                if (print[i])
                    printf("%c",s[i]);
            }
            puts("");
            return 0;
        }
    }
    if (sum[mod] == 0) {
        int cnt = len - 2;
        int del = 0, fflag = 0;
        for (int i = len - 1; i >= 0; i --) {
            if ((s[i] - '0') % 3 == 3 - mod) {
                ++ del;
                print[i] = 0;
                if (i == 0) fflag = 1;
                if (del == 2) break;
            }
        }
        if (del <= 1) {
            puts("-1");
            return 0;
        }
        if (fflag) {
            int i = 1;
            int ffflag = 0;
            while (i < len && (s[i] == '0' || print[i] == 0)) {
                if (print[i] == 0) cnt ++;
                if (s[i] == '0') ffflag = 1;
                print[i] = 0;
                i ++;
                -- cnt;
            }
            if (cnt == 0) {
                if (ffflag == 1) {
                    puts("0");
                } else
                    puts("-1");
                return 0;
            }
        }
        for (int i = 0; i < len; i ++) {
            if (print[i])
                printf("%c",s[i]);
        }
        puts("");
        return 0;
    }


    return 0;
}


