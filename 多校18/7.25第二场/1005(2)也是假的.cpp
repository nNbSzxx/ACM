#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 2000;
char a[2010][2010];
 int cnt[2010][2010];

bool check()
{
    memset(cnt, 0, sizeof cnt);
    for (int x = 1; x <= MAX; x ++) {
        for (int y = 1; y <= MAX; y ++) {
            if (a[x][y] == '1') {
                for (int r = 1; r <= MAX; r ++) {

                    if(a[r][y] == '1') {
                        ++ cnt[min(r, x)][max(r, x)];
                        if (cnt[min(r, x)][max(r, x)] > 1) {
                            printf("(x, y): %d %d\n(r, x): %d %d\n", x, y, r, x);
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int main()
{
    memset(a, 0, sizeof a);
    for (int i = 1; i <= MAX; i ++) {
        for (int j = 1; j <= MAX; j ++) {
            a[i][j] = '0';
        }
    }
    for (int i = 1; i <= MAX; i ++) {
        a[i][i] = '1';
    }
/*
    for (int i = 1; i + 1 <= MAX; i ++) {
        a[i][i + 1] = '1';
    }
*/
    int col = 1;
    int dif = 1;
    while (true) {
        col = col + dif;
        if (col > MAX) {
            break;
        }
        for (int i = col, j = 1; i <= MAX; i ++, j ++) {
            a[j][i] = '1';
        }
        dif += 1;
    }


    puts("2000");

    for (int i = 1; i <= MAX; i ++) {
        puts(a[i] + 1);
    }


    int sum = 0;
    for (int i = 1; i <= MAX; i ++) {
        for (int j = 1; j <= MAX; j ++) {
            sum += a[i][j] - '0';
        }
    }
    //printf("%d\n", sum);

    // printf("%d\n", strlen(a[1] + 1));

    //bool succ = check();




    return 0;
}

