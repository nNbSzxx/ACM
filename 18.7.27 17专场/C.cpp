#include <iostream>
#include <cstdio>
using namespace std;
const int MAX = 2e6 + 10;
char s1[MAX], s2[MAX];

int main()
{
    int n;

    scanf("%d", &n);
    scanf(" %s %s", s1, s2);
    int ans1 = 0, ans2 = 0;
    int turn = 0;
    for (int i = 0; i < 2 * n; i ++) {
        if (s1[i] == '1' && s2[i] == '1') {
            if (turn == 0) {
                ans1 += 1;
                turn ^= 1;
            } else {
                ans2 += 1;
                turn ^= 1;
            }
        }
    }
    for (int i = 0; i < 2 * n; i ++) {
        if (s1[i] == '1' && s2[i] == '1') {
            continue;
        }
        if ((s1[i] == '1' && s2[i] == '0') || (s1[i] == '0' && s2[i] == '1')) {
            if (turn == 0) {
                if (s1[i] == '1') {
                    ans1 += 1;
                }
                turn ^= 1;
            } else {
                if (s2[i] == '1') {
                    ans2 += 1;
                }
                turn ^= 1;
            }
        }
    }
    //printf("%d %d\n", ans1, ans2);
    if (ans1 > ans2) {
        puts("First");
    } else if (ans1 < ans2) {
        puts("Second");
    } else {
        puts("Draw");
    }
    return 0;
}
