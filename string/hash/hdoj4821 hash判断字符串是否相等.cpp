#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <map>
using namespace std;
const int MAX = 1e5 + 10;
//const unsigned long long MOD = 1e9 + 7;
const unsigned long long P = 233;

int m, l, n;
char s[MAX];
unsigned long long hsh[MAX];
unsigned long long base[MAX];
map<unsigned long long, int> mp;

void init()
{
    base[0] = 1;
    for (int i = 1; i < MAX; i ++) {
        base[i] = (base[i - 1] * P);
    }
}

unsigned long long gethash(int l, int r)
{
    return (hsh[r] - hsh[l - 1] * base[r - l + 1]);
}

int main()
{
    init();
    while (~scanf("%d%d", &m, &l)) {
        scanf(" %s", s + 1);
        n = strlen(s + 1);
        hsh[0] = 0;
        for (int i = 1; i <= n; i ++) {
            hsh[i] = (hsh[i - 1] * P + (s[i] - 'a' + 1));
        }
        int ans = 0;
        for (int i = 1; i <= l && i + m * l - 1 <= n; i ++) {
            mp.clear();
            for (int j = i; j <= i + m * l - 1; j += l) {
                mp[gethash(j, j + l - 1)] ++;
            }
            if (mp.size() == m) {
                ++ ans;
            }
            for (int j = i + m * l; j + l - 1 <= n; j += l) {
                mp[gethash(j, j + l - 1)] ++;
                unsigned long long h = gethash(j - m * l, j - m * l + l - 1);
                mp[h] --;
                if (mp[h] == 0) {
                    mp.erase(h);
                }
                if (mp.size() == m) {
                    ++ ans;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
