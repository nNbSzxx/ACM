#include <bits/stdc++.h>
using namespace std;
const int MAX = 1e6 + 10;
int sumdg[MAX];
vector<int> s[100];

int main()
{
    int n;
    freopen("digits.in", "r", stdin);
    freopen("digits.out", "w", stdout);
    scanf("%d", &n);
    for (int i = 1; i < MAX; i ++) {
        int m;
        int t = i;
        while (t) {
            sumdg[i] += t % 10;
            t /= 10;
        }
        s[sumdg[i]].push_back(i);
    }

    long long minn = 0x3f3f3f3f3f3f3f3f;
    for (int i = 0; i < 100; i ++) {
        if (s[i].size() >= n) {
            long long sum = 0;
            for (int j = 0; j < n; j ++) {
                sum += s[i][j];
            }
            if (minn > sum) {
                minn = sum;
            }
        }
    }

    printf("%lld\n", minn);
    return 0;
}
