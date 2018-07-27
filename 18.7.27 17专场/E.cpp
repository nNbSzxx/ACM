#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    int t;
    int sumodd = 0, sumeven = 0;
    for (int i = 1; i <= n; i ++) {
        scanf("%d", &t);
        if (t & 1) {
            ++ sumodd;
        } else {
            ++ sumeven;
        }
    }
    int cnt = n - k;
    int d = cnt / 2;
    int s = cnt - d;
    if (d >= sumodd || k == 0) {
        puts("Daenerys");
        return 0;
    }
    if (n == k) {
        if (sumodd & 1) {
            puts("Stannis");
        } else {
            puts("Daenerys");
        }
        return 0;
    }
    if (d == s) {
        if (s < sumeven) {
            puts("Daenerys");
        } else {
            int judge = sumodd - (d - sumeven) - s;
            if (judge & 1) {
                puts("Stannis");
            } else {
                puts("Daenerys");
            }
        }
    } else {
        // s > d
        if (d < sumeven) {
            puts("Stannis");
        } else {
            int judge = sumodd - (d - sumeven) - s;
            if (judge & 1) {
                puts("Stannis");
            } else {
                puts("Daenerys");
            }
        }
    }
    return 0;
}
