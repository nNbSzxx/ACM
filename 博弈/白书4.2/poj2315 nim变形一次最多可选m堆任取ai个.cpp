// n堆石子，可以从中选1 - m堆，每堆至少取一个最多取完，每堆取的可以不一样多
// 类似nim，nim是最多取1堆，是做二进制下不进位加法，即%2加法
// 这题还是把数字拆分成二进制，每位分别做%(m + 1)的加法，不为零则先手必胜
// 可以证明，必胜态可以转移到必败态，必败态只能转移到必胜态
// 题目中要求一次最多拿k个，因此可以先对每堆石子模(k + 1)，然后按上述方法做
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;
const int MAX = 33;
const double PI = 3.14159265358979323846264338327950288;

int n, m, l, r;
int s[MAX];
int sum[MAX];

int main()
{
    while (~scanf("%d%d%d%d", &n, &m, &l, &r)) {
        int k = int(l / (2 * PI * r));
        for (int i = 1; i <= n; i ++) {
            scanf("%d", &s[i]);
            s[i] = int(s[i] / (2 * PI * r)) + 1;
            s[i] %= (k + 1);
        }
        memset(sum, 0, sizeof sum);
        for (int i = 1; i <= n; i ++) {
            int t = s[i];
            int j = 0;
            while (t) {
                sum[j] += t & 1;
                t >>= 1;
                ++ j;
            }
        }
        bool win = 0;
        for (int i = 0; i < MAX; i ++) {
            sum[i] %= (m + 1);
            if (sum[i]) {
                win = 1;
                break;
            }
        }
        if (win) {
            puts("Alice");
        } else {
            puts("Bob");
        }
    }
    return 0;
}
