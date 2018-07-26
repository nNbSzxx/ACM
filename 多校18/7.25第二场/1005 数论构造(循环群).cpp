#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;
const int MAX = 2500;
char m[MAX][MAX];
const int p = 47;

int main()
{
    for (int i = 0; i < 2000; i ++) {
        for (int j = 0; j < 2000; j ++) {
            m[i][j] = '0';
        }
    }
    for (int i = 0; i < 2000; i ++) {
        for (int j = 0; j < p; j ++) {
            m[i][j * p + (i / p + j * (i % p)) % p] = '1';
        }
    }
    puts("2000");
    for (int i = 0; i < 2000; i ++) {
        m[i][2000] = '\0';
        puts(m[i]);
    }

    /*
    int cnt = 0;
    for (int i = 0; i < 2000; i ++) {
        for (int j = 0; j < 2000; j ++) {
            cnt += m[i][j] - '0';
        }
    }
    printf("%d\n", cnt);
    */

    return 0;
}
