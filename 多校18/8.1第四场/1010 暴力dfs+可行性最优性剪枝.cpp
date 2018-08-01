#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 16 * 16;
int row[16][4];
int col[16][4];
int ans, tans;

bool checkRow(int blockRow)
{
    int s = blockRow * 4;
    for (int j = 0; j < 4; j ++) {
        if ((row[s][j] | row[s + 1][j] | row[s + 2][j] | row[s + 3][j]) != 0xffff)
            return false;
    }
    return true;
}

bool checkCol()
{
    for (int i = 0; i < 4; i ++) {
        int s = i;
        for (int j = 0; j < 4; j ++) {
            if ((col[s][j] | col[s + 4][j] | col[s + 8][j] | col[s + 12][j]) != 0xffff)
                return false;
        }
    }

    return true;
}

void rot(int b, int tim)
{

    if (tim < 0) {
        tim += 4;
    }

    for (int k = 0; k < tim; k ++) {

        int temp[4];
        for (int i = 0; i < 4; i ++) {
            temp[i] = row[b][i];
        }

        for (int i = 0; i < 4; i ++) {
            row[b][i] = col[b][i];
        }

        for (int i = 0; i < 4; i ++) {
            col[b][i] = temp[3 - i];
        }

    }
    return ;
}

void dfs(int id)
{
    if (id == 16) {
        if (checkRow(3) && checkCol()) {
            ans = min(ans, tans);
        }
        return ;
    }
    if ((id & 3) == 0 && id != 0) {
        if (!checkRow(id / 4 - 1)) {
            return ;
        }
    }
    for (int i = 0; i < 4; i ++) {
        if (tans + i < ans) {
            rot(id, i);
            tans += i;
            dfs(id + 1);
            tans -= i;
            rot(id, -i);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t --) {
        memset(row, 0, sizeof row);
        memset(col, 0, sizeof col);
        char c;
        for (int i = 0; i < 16; i ++) {
            for (int j = 0; j < 16; j ++) {
                scanf(" %c", &c);
                int shift;
                if (c >= '0' && c <= '9') {
                    shift = c - '0';
                } else {
                    shift = 10 + c - 'A';
                }

                int b = i / 4 * 4 + j / 4;
                row[b][i & 3] |= (1 << shift);
                col[b][j & 3] |= (1 << shift);
            }
        }
        ans = 0x3f3f3f3f;
        // printf("%d\n", ans);
        tans = 0;

        dfs(0);
        printf("%d\n", ans);
    }
    return 0;
}
